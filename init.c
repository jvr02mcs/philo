#include "philo.h"

static int	init_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static void asign_forks(t_philo *philo, size_t i, size_t n)
{
	philo->l_fork = i;
	if (i + 1 == n)
		philo->r_fork = 0;
	else
		philo->r_fork = i + 1;
}

static void	init_philo(t_data	*data)
{
	size_t	i;
	i = 0;
	while (i < data->n_of_philos)
	{
		data->philo[i].n = i + 1;
		data->philo[i].ended = 0;
		data->philo[i].meals = 0;
		asign_forks(&data->philo[i], i, data->n_of_philos);
		data->philo[i].data = data;
		i++;
	}
}

int	init_all(t_data	*data, int argc, char **argv)
{
	data->n_of_philos = ft_atol(argv[1]);
	data->time_to = asign_times(argv + 1, argc - 2);
	data->start_time = get_time();
	data->end = 0;
	pthread_mutex_init(&data->mwrite, NULL);
	data->philo = malloc(sizeof(t_philo) * data->n_of_philos);
	if (!data->philo)
		return (ft_error("Philos memory alloc failed"));
	data->forks = malloc(sizeof(t_fork) * data->n_of_philos);
	if (!data->forks)
		return	(ft_error("Forks memory alloc failed"));
	if (init_forks(data))
		return (ft_error("Forks initialization failed"));
	init_philo(data);
	return (0);
}
