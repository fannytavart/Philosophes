/*
** check_actions.c for check philosophers actions in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_philo
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Fri Mar 10 19:38:17 2017 Fanny Tavart
** Last update Sat Mar 18 20:04:33 2017 Ronan Boiteau
*/

#include <extern.h>
#include <stdio.h>
#include "philo.h"

static t_chopstick	*take_chopstick(t_chopstick *chopsticks,
					unsigned chopstick_id)
{
  pthread_mutex_lock(&g_m_chopstick[chopstick_id]);
  chopsticks[chopstick_id].state = TAKEN;
  lphilo_take_chopstick(&g_m_chopstick[chopstick_id]);
  pthread_mutex_unlock(&g_m_chopstick[chopstick_id]);
  return (chopsticks);
}

char		can_eat(int philo_id,
			t_philo *philo,
			t_chopstick *chopsticks)
{
  unsigned	right_chopstick;

  right_chopstick = (philo_id + 1 < g_info.nb_philo) ? philo_id + 1 : 0;
  if (chopsticks[philo_id].state == FREE
      && chopsticks[right_chopstick].state == FREE)
    {
      if (philo->nb_lunch == g_info.occ - 1 && philo_id != 0)
      	{
	  while (g_info.done != 1);
	  return (0);
      	}
      chopsticks = take_chopstick(chopsticks, philo_id);
      chopsticks = take_chopstick(chopsticks, right_chopstick);
      philo->nb_lunch += 1;
      if (philo->nb_lunch == g_info.occ)
	{
	  pthread_mutex_lock(&g_m_info);
	  g_info.done = 1;
	  pthread_mutex_unlock(&g_m_info);
	  return (1);
	}
      return (1);
    }
  return (0);
}

char		can_think(int philo_id,
			  unsigned *chop_id,
			  t_philo *philos,
			  t_chopstick *chopsticks)
{
  unsigned	right_chopstick;

  right_chopstick = (philo_id + 1 < g_info.nb_philo) ? philo_id + 1 : 0;
  if (chopsticks[philo_id].state == FREE)
    {
      chopsticks = take_chopstick(chopsticks, philo_id);
      *chop_id = philo_id;
      return (1);
    }
  if (chopsticks[right_chopstick].state == FREE)
    {
      chopsticks = take_chopstick(chopsticks, right_chopstick);
      *chop_id = right_chopstick;
      return (1);
    }
  return (0);
}
