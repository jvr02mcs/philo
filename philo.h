#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data t_data;
typedef pthread_mutex_t t_mutex;

typedef enum e_act
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING,
	FINISHED,
	INIT
}	t_act;

typedef struct s_times
{
	size_t	eat;
	size_t	sleep;
	size_t	die;
}	t_times;

typedef struct s_philo
{
	pthread_t	thread;
	size_t		n;
	size_t		meals;
	size_t		r_fork;
	size_t		l_fork;
	size_t		last_meal;
	t_act		action;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	size_t		n_of_philos;
	t_times		time_to;
	size_t		meals4each;
	size_t		start_time;
	int			end;

	pthread_t	m_thread;
	pthread_t	th_check_time;
	pthread_t	th_check_meals;

	t_mutex		iter_mutex;
	t_mutex		action_mutex;
	t_mutex		mwrite;
	t_mutex		lm_mutex;
	t_mutex		eating_mutex;
	t_mutex		*forks;
	
	t_philo		*philo;
}	t_data;

int		ft_error(char *error);
void	ft_msleep(size_t usec);

/*	take forks	*/
int		take_both_forks(t_philo *philo);

/*	philo	*/
int		handle_one(t_philo *philo);
void	philosophers(t_data *data);
void	*routine(void *arg);

/*	checkers	*/
int	death_management(t_philo *philo);
int		all_philos_has_eaten(t_data	*data);
void	*check_time(void *arg);
void	*check_meals(void *arg);

/*	leave forks	*/
void	leave_both_forks(t_philo *philo);
void	leave_fork(t_mutex *fork_mutex);

/*	init	*/
int		args_not_valid(int argc, char **argv);
int		init_all(t_data	*data, int argc, char **argv);
t_times	asign_times(char **arg);

void	print_mes(t_data *d, size_t philo_n, char *mes);

/*	action_management	*/
void	set_action(t_philo *philo, t_act action);
t_act	get_action(t_philo *philo);

/*	flags_iteration	*/
void	set_flag(t_data *data, int flag);
int 	get_flag(t_data *data);

/*	times	*/
void	set_last_meal(t_data *data, t_philo *philo);
size_t	get_last_meal(t_data *data, t_philo *philo);

/*	utils	*/
size_t	get_time(void);
size_t	ft_strlen(char *s);
long	ft_atol(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif