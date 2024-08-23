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

typedef struct s_times
{
	size_t	eat;
	size_t	sleep;
	size_t	die;
	size_t	each;
}	t_times;

typedef pthread_mutex_t t_mutex;

typedef struct s_fork
{
	t_mutex	fork;
	size_t	n;
}	t_fork;

typedef struct s_philo
{
	size_t		n;
	size_t		meals;
	int			ended;
	pthread_t		thread;
	t_fork	*r_fork;
	t_fork	*l_fork;
}					t_philo;

typedef struct s_data
{
	t_times	time_to;
	size_t	n_of_philos;
	size_t	start_time;
	int		end ;
	t_fork	*forks;
	t_philo	*philo;
}	t_data;

int	ft_error(char *error);
size_t	ft_strlen(char *s);
long	ft_atol(const char *str);
t_times	asign_times(char **arg, int n);
int		mutex_action(t_mutex *mutex, int f);
int		ft_error_in_mutex(int error, int w);
int		args_not_valid(int argc, char **argv);
int		init_all(t_data	*data, int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif