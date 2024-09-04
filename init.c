#include "philo.h"

static int	init_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i + 1 < data->n_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			return (1);
		data->forks[i].in_use = 0;
		i++;
	}
	return (0);
}

static void asign_forks(t_philo *philo, size_t i, size_t n)
{
	if (philo->n == 1 && n != 1)
		philo->l_fork = n - 1;
	else
		philo->l_fork = i - 1;
	printf("philo[%ld], [%ld]left\n", philo->n, philo->l_fork);
	philo->r_fork = i;
	printf("philo[%ld], [%ld]right\n", philo->n, philo->r_fork);
	printf("---------------\n");
}

static void	init_philo(t_data	*data)
{
	size_t	i;
	i = 0;
	while (i < data->n_of_philos)
	{
		data->philo[i].n = i + 1;
		data->philo[i].meals = 0;
		data->philo[i].last_time = 0;
		pthread_mutex_init(&data->philo[i].eating, NULL);
		asign_forks(&data->philo[i], i, data->n_of_philos);
		data->philo[i].data = data;
		sleep(1);
		i++;
	}
}

int	init_all(t_data	*data, int argc, char **argv)
{
	data->n_of_philos = ft_atol(argv[1]);
	data->time_to = asign_times(argv + 1, argc - 2);
	data->start_time = get_time();
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
