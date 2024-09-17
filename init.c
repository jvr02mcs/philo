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
		data->meals4each = 0;
}

static void	asign_fork(t_philo *philo, int n, int i)
{
	if (philo->n == 1 && n != 1)
		philo->left = n - 1;
	else
		philo->left = i - 1;
	philo->right = i;
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
		asign_fork(&data->philos[i], data->n_philos, i);
		data->philos[i].data = data;
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
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
	{
		return (1);
	}
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	if (!data->forks)
	{
		free(data->philos);
		return (1);
	}
	init_philo(data);
	init_forks(data);
	pthread_mutex_init(&data->write_mtx, NULL);
	return (0);
}
