#include <unistd.h>
#include <stdio.h>
#include "extern.h"
#include "philo.h"

static void	release_chopstick(unsigned chopstick_id)
{
  pthread_mutex_lock(&g_m_chopstick[chopstick_id]);
  g_chopsticks[chopstick_id].state = FREE;
  lphilo_release_chopstick(&g_m_chopstick[chopstick_id]);
  pthread_mutex_unlock(&g_m_chopstick[chopstick_id]);
}

void		philo_eats(t_philo *philo)
{
  philo->activity = EATING;
  lphilo_eat();
  if (philo->id + 1 < g_info.nb_philo)
    release_chopstick(philo->id + 1);
  else
    release_chopstick(0);
  release_chopstick(philo->id);
}

void		philo_thinks(t_philo *philo, int chop_id)
{
  philo->activity = THINKING;
  philo->nb_reflection += 1;
  lphilo_think();
  if (chop_id != -1)
    release_chopstick(chop_id);
}

void		philo_rests(t_philo *philo)
{
  philo->nb_sleep += 1;
  philo->activity = RESTING;
  lphilo_sleep();
}
