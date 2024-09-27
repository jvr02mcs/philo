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
typedef struct s_data	t_data;

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
	int			n;
	int			meals;
	int			eating;
	uint64_t	last_meal;
	int			done;
	size_t		death;
	pthread_t	th;
	pthread_t	check_th;
	t_mutex		*left;
	t_mutex		*right;
	t_data		*data;
}	t_philo;

struct s_data
{
	int			n_philos;
	size_t		t2die;
	size_t		t2eat;
	size_t		t2sleep;
	int			meals4each;
	int			end;
	size_t		start_time;
	t_mutex		write_mtx;
	t_mutex		mutex;
	t_philo		*philos;
	t_mutex		*forks;
	pthread_t	meals_th;
	pthread_t	time_th;
};

/*utils*/
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_mes(t_philo *philo, char *mes);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
size_t	get_time(void);
void	ft_sleepms(size_t time2);
/*args*/
int		args_not_valid(int argc, char **argv);
/*init*/
int		init_data(t_data *data, int argc, char **argv);
void	destroy_data(t_data *data);
/*actions*/
void	take_forks(t_philo *philo);
void	leave_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
/*philo*/
int		not_in_time(t_philo *philo);
void	*time_check(void *arg);
void	*meals_check(void *arg);
void	*check(void *arg);
void	*routine(void *arg);
void	philosophers(t_data *data);
#endif
