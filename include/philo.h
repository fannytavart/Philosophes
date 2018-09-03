#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

extern pthread_mutex_t	*g_m_philo;
extern pthread_mutex_t	*g_m_chopstick;
extern pthread_mutex_t	g_m_info;

typedef	struct	s_info
{
  int		nb_philo;
  int		occ;
  char		done;
  int		created;
}		t_info;

extern t_info	g_info;

typedef enum	e_activity
  {
    THINKING,
    EATING,
    RESTING,
    NB_ACTIVITY
  }		t_activity;

typedef struct	s_philo
{
  t_activity	activity;
  int		id;
  int		nb_lunch;
  int		nb_reflection;
  int		nb_sleep;
}		t_philo;

extern t_philo	*g_philos;

typedef enum	e_chopstick_state
  {
    TAKEN,
    FREE,
    NB_STATE
  }		t_chopstick_state;

typedef struct		s_chopstick
{
  t_chopstick_state	state;
}			t_chopstick;

extern t_chopstick	*g_chopsticks;

char		get_args(int ac, char **av, t_info *info);
int		get_min(void);
int		create_thread(pthread_t *thread_ph,
			      unsigned nb_philo,
			      t_philo *philos);
int		join_thread(pthread_t *thread_ph, unsigned nb_philo);
pthread_mutex_t	*init_tab_mutex(unsigned nb_philo,
				pthread_mutex_t *tab);
t_chopstick	*init_chopsticks(unsigned nb_philo, t_chopstick *chopsticks);
t_philo		*init_philos(unsigned nb_philo, t_philo *philos);
char		can_eat(int philo_id,
			t_philo *philo,
			t_chopstick *chopsticks);
char		can_think(int philo_id,
			  int *chop_id,
			  t_chopstick *chopsticks);
void		*change_activity(void *philos);
void		philo_eats(t_philo *philo);
void		philo_thinks(t_philo *philo, int chop_id);
void		philo_rests(t_philo *philo);

#endif /* !PHILO_H_ */
