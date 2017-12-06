/*
** extern.h for philo in /home/ronan/Documents/PSU_2016_philo
** 
** Made by Ronan Boiteau
** Login   <ronan.boiteau@epitech.net>
** 
** Started on  Sun Mar 19 18:30:11 2017 Ronan Boiteau
** Last update Sun Mar 19 18:30:17 2017 Ronan Boiteau
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

# include <pthread.h>

int	RCFStartup(int ac, char **av);
void	RCFCleanup();
int	lphilo_eat();
int	lphilo_sleep();
int	lphilo_think();
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* __LIBRICEFEREE_EXTERN__ */
