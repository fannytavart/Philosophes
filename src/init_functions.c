#include <stdlib.h>
#include "philo.h"

pthread_mutex_t	*init_tab_mutex(unsigned nb_philo,
				pthread_mutex_t *tab)
{
  unsigned	idx;

  if ((tab = malloc((sizeof(pthread_mutex_t) * nb_philo))) == NULL)
    return (NULL);
  idx = 0;
  while (idx < nb_philo)
    {
      tab[idx] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
      idx += 1;
    }
  return (tab);
}

t_chopstick	*init_chopsticks(unsigned nb_philo, t_chopstick *chopsticks)
{
  unsigned	idx;

  if ((chopsticks = malloc((sizeof(t_chopstick) * nb_philo))) == NULL)
    return (NULL);
  idx = 0;
  while (idx < nb_philo)
    {
      chopsticks[idx].state = FREE;
      idx += 1;
    }
  return (chopsticks);
}

t_philo		*init_philos(unsigned nb_philo, t_philo *philos)
{
  unsigned	idx;

  if ((philos = malloc((sizeof(t_philo) * nb_philo))) == NULL)
    return (NULL);
  idx = 0;
  while (idx < nb_philo)
    {
      philos[idx].id = idx;
      philos[idx].activity = RESTING;
      philos[idx].nb_lunch = 0;
      philos[idx].nb_reflection = 0;
      philos[idx].nb_sleep = 0;
      idx += 1;
    }
  return (philos);
}
