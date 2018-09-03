#include "philo.h"

int		get_min(void)
{
  int		idx;
  int		min;

  idx = 0;
  min = g_philos[0].nb_reflection;
  while (idx < g_info.nb_philo)
    {
      if (g_philos[idx].nb_reflection < min)
	min = g_philos[idx].nb_reflection;
      else if (g_philos[idx].nb_lunch < min)
	min = g_philos[idx].nb_lunch;
      else if (g_philos[idx].nb_sleep < min)
	min = g_philos[idx].nb_sleep;
      idx += 1;
    }
  return (min);
}
