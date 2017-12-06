/*
** get_min_activity.c for get min activity in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_philo/src
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Tue Mar 14 21:08:39 2017 Fanny Tavart
** Last update Sat Mar 18 20:05:44 2017 Ronan Boiteau
*/

#include "philo.h"

int		get_min(t_activity activity)
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
