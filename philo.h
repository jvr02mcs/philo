#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_data t_data;

typedef enum e_action
{
	DEAD,
	EAT,
	SLEEP,
	THINK,
	START
}	t_action;

typedef struct s_philo
{
	pthread_t	th;
	int			n;
	int			left;
	int			right;
	int			meals;
	t_data		*data;
}	t_philo;

struct s_data
{
	int		n_philos;
	int		t2die;
	int		t2eat;
	int		t2sleep;
	int		meals4each;
	size_t	start_time;
	t_mutex	write_mtx;
	t_mutex	meals_mtx;
	t_philo	*philos;
	t_mutex	*forks;
};

/*utils*/
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_mes(t_data *d, size_t philo_n, char *mes);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
size_t	get_time(void);
void	ft_sleep(size_t time2);
/*args*/
int		args_not_valid(int argc, char **argv);
/*init*/
int		init_data(t_data *data, int argc, char **argv);
void	destroy_data(t_data *data);
/*philo*/
void	philosophers(t_data *data);
int		eating(t_philo *philo);
void	*routine(void *arg);
#endif