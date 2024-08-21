#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/wait.h>
# include <limits.h>
# include <sys/types.h>
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

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_program
{
	t_philo	*philos;
	t_times	times_to;
	size_t	n_of_philos;
}	t_program;


int		args_not_valid(int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atol(const char *str);
size_t	ft_strlen(char *s);

#endif