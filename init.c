#include "philo.h"

static void	asign_fork(t_philo *philo, t_fork *fork, size_t i, size_t n)
{
	size_t	fn;

	sleep(1);
	fn = i;
	philo->l_fork = &fork[fn];
	printf("philosopher[%ld] has fork[%ld] for l hand\n", i + 1, fn);
	fn = 0;
	sleep(1);
	if (philo->n != n)
		fn = philo->n;
	philo->r_fork = &fork[fn];
	printf("philosopher[%ld] has fork[%ld] for r hand\n", i + 1, fn);
}
static int	init_forks(t_data	*data)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < data->n_of_philos)
	{
		ret = mutex_action(&data->forks[i].fork, 2);
		if (ret != 0)
			return (ft_error_in_mutex(ret, 1));
		printf("fork[%ld] initialized\n", i);
		sleep(1);
		data->forks[i].n = i;
		i++;
	}
	return (0);
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
		printf("n of philo = %ld, ended : %d, meals %ld\n", data->philo[i].n, data->philo[i].ended, data->philo[i].meals);
		asign_fork(&data->philo[i], &data->forks[i], i, data->n_of_philos);
		i++;
	}
}

int	init_all(t_data	*data, int argc, char **argv)
{
	data->n_of_philos = ft_atol(argv[1]);
	data->time_to = asign_times(argv + 1, argc - 2);
	data->start_time = 'x';
	data->end = 0;
	data->forks = malloc(sizeof(t_fork) * data->n_of_philos);
	if (!data->forks)
		return (ft_error("Forks memory alloc"));
	data->philo = malloc(sizeof(t_philo) * data->n_of_philos);
	if (!data->philo)
		return (ft_error("Philos memory alloc"));
	init_forks(data);
	init_philo(data);
	return (0);
}