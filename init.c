#include "philo.h"

static void	asign_args(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->t2die = ft_atoi(argv[2]);
	data->t2eat = ft_atoi(argv[3]);
	data->t2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals4each = ft_atoi(argv[5]);
	else
		data->meals4each = -1;
}

static void	asign_fork(t_data *data, int i)
{
	int	max;

	max = data->n_philos;
	data->philos[i].left = &data->forks[i];
	data->philos[i].right = &data->forks[(i + 1) % max];
}

static void	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philos;
	while (i < data->n_philos)
	{
		philo[i].n = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = 0;
		philo[i].eating = 0;
		philo[i].done = 0;
		asign_fork(data, i);
		data->philos[i].data = data;
		philo[i].death = 0;
		i++;
	}
}

static void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int	init_data(t_data *data, int argc, char **argv)
{
	asign_args(argc, argv, data);
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	if (!data->forks)
		return (1);
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
	{
		free(data->forks);
		return (1);
	}
	init_forks(data);
	init_philo(data);
	pthread_mutex_init(&data->write_mtx, NULL);
	pthread_mutex_init(&data->mutex, NULL);
	data->end = 0;
	data->start_time = 0;
	return (0);
}
