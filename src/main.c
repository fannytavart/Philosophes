#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "extern.h"
#include "my.h"

t_philo		*g_philos = NULL;
t_chopstick	*g_chopsticks = NULL;
t_info		g_info;
pthread_mutex_t	*g_m_philo = NULL;
pthread_mutex_t	*g_m_chopstick = NULL;
pthread_mutex_t	g_m_info = PTHREAD_MUTEX_INITIALIZER;

static void	eat_or_think(t_philo *philo, int chop_id, char just_eat)
{
  if (get_min() >= philo->nb_lunch &&
      can_eat(philo->id, philo, g_chopsticks))
    {
      philo_eats(philo);
      if (just_eat == 1)
	return ;
    }
  else if (get_min() >= philo->nb_reflection &&
	   can_think(philo->id, &chop_id, g_chopsticks))
    philo_thinks(philo, chop_id);
}

void		*change_activity(void *philos)
{
  t_philo	*philo;
  int		chop_id;

  philo = (t_philo *)philos;
  pthread_mutex_lock(&g_m_info);
  g_info.created += 1;
  pthread_mutex_unlock(&g_m_info);
  while (g_info.created != g_info.nb_philo);
  chop_id = 0;
  while (g_info.done != 1)
    {
      if (philo->activity == RESTING)
	eat_or_think(philo, chop_id, 0);
      else if (philo->activity == THINKING)
	eat_or_think(philo, chop_id, 1);
      else if (philo->activity == EATING || get_min() >= philo->nb_sleep)
	philo_rests(philo);
      pthread_mutex_lock(&g_m_philo[philo->id]);
      g_philos[philo->id] = *philo;
      pthread_mutex_unlock(&g_m_philo[philo->id]);
    }
  pthread_exit(0);
}

static int	exit_philo(int status)
{
  if (g_philos != NULL)
    free(g_philos);
  if (g_chopsticks != NULL)
    free(g_chopsticks);
  if (g_m_philo != NULL)
    free(g_m_philo);
  if (g_m_chopstick != NULL)
    free(g_m_chopstick);
  RCFCleanup();
  return (status);
}

int		main(int ac, char **av)
{
  pthread_t	*thread_ph;

  RCFStartup(ac, av);
  if (get_args(ac, av, &g_info) == 1 ||
      (g_philos = init_philos(g_info.nb_philo, g_philos)) == NULL ||
      (g_chopsticks = init_chopsticks(g_info.nb_philo, g_chopsticks)) == NULL ||
      (g_m_chopstick = init_tab_mutex(g_info.nb_philo, g_m_chopstick)) == NULL
      || (g_m_philo = init_tab_mutex(g_info.nb_philo, g_m_philo)) == NULL ||
      (thread_ph = malloc(sizeof(pthread_t) * g_info.nb_philo)) == NULL ||
      create_thread(thread_ph, g_info.nb_philo, g_philos) != 0 ||
      join_thread(thread_ph, g_info.nb_philo) != 0)
    return (exit_philo(1));
  return (exit_philo(0));
}
