#include "philo.h"

static void	init_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

static void asign_forks(t_philo *philo, size_t i, size_t n)
{
	if (philo->n == 1 && n != 1)
		philo->l_fork = n - 1;
	else
		philo->l_fork = i - 1;
	philo->r_fork = i;
}

static void	init_philo(t_data	*data)
{
	size_t	i;
	i = 0;
	while (i < data->n_of_philos)
	{
		data->philo[i].n = i + 1;
		data->philo[i].meals = 0;
		data->philo[i].finished = 0;
		data->philo[i].last_time = 0;
		pthread_mutex_init(&data->philo[i].eating, NULL);
		asign_forks(&data->philo[i], i, data->n_of_philos);
		data->philo[i].data = data;
		i++;
	}
}

int	init_all(t_data	*data, int argc, char **argv)
{
	data->n_of_philos = ft_atol(argv[1]);
	data->end = 0;
	data->time_to = asign_times(argv);
	if (argc == 6)
		data->meals4each = ft_atol(argv[5]);
	else
		data->meals4each = 0;
	pthread_mutex_init(&data->mwrite, NULL);
	data->philo = malloc(sizeof(t_philo) * data->n_of_philos);
	if (!data->philo)
		return (ft_error("Philos memory alloc failed"));
	data->forks = malloc(sizeof(t_mutex) * data->n_of_philos);
	if (!data->forks)
		return	(ft_error("Forks memory alloc failed"));
	init_forks(data);
	init_philo(data);
	data->start_time = get_time();
	return (0);
}
