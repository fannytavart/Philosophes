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
