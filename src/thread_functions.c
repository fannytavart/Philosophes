#include "philo.h"

int		create_thread(pthread_t *thread_ph,
			      unsigned nb_philo,
			      t_philo *philos)
{
  unsigned	idx;

  idx = 0;
  while (idx < nb_philo)
    {
      if (pthread_create(&thread_ph[idx], NULL, change_activity,
			 (void *)&philos[idx]) != 0)
	return (1);
      idx += 1;
    }
  return (0);
}

int		join_thread(pthread_t *thread_ph, unsigned nb_philo)
{
  unsigned	idx;

  idx = 0;
  while (idx < nb_philo)
    {
      if (pthread_join(thread_ph[idx], NULL) != 0)
	return (1);
      idx += 1;
    }
  return (0);
}
