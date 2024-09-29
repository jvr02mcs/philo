/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:27 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 20:17:50 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	int			n_philos;
	uint64_t	t2die;
	uint64_t	t2eat;
	uint64_t	t2sleep;
	uint64_t	start_time;
	int			meals4each;
	int			someone_dead;
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
int			init_data(t_data *data, char **argv);
int			init_forks(t_table *table);
int			init_philos(t_table *table);

//free
void		free_all(t_table *table);
void		free_forks(t_table *table, int n);
void		free_philos_mutex(t_table *table, int n);
//args
int			args_not_valid(int argc, char **argv);
//program
void		printmes(t_philo *philo, char *mes);
void		*routine(void *arg);
//	actions
int			take_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

int			is_everyone_alive(t_philo *philo);
int			someone_is_dead(t_data *data);
void		*monitor(void *arg);

#endif
