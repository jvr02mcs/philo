#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/time.h>


typedef pthread_mutex_t t_mutex;
typedef pthread_mutex_t *hand;

typedef struct s_data
{
	int			n_philos;
	u_int64_t	t2die;
	u_int64_t	t2eat;
	u_int64_t	t2sleep;
	u_int64_t	start_time;
	int			meals4each;
	t_mutex		mtx;
}	t_data;

typedef struct s_philo
{
	int			n;
	int			meals;
	pthread_t	th;
	uint64_t	last_meal;
	t_data		*data;
	t_mutex		*right;
	t_mutex		*left;
	t_mutex		*write_mtx;
	t_mutex		eating_mtx;
	t_mutex		death_mtx;
}	t_philo;

typedef struct s_table
{
	t_data		data;
	t_mutex		*forks;
	t_mutex		write;
	t_philo		*philo;
}	t_table;

uint64_t	get_time(void);
void		ft_sleepms(size_t time2);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
size_t		ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

//init
int		init_data(t_data *data, char **argv);
int		init_forks(t_table *table);
int		init_philos(t_table *table);

//free
void		free_forks(t_table *table);

//args
int			args_not_valid(int argc, char **argv);

#endif