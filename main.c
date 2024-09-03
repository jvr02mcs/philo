#include "philo.h"

void	print_mes(t_philo *philo, size_t philo_n, char *mes)
{
	philo->last_time = get_time();
	pthread_mutex_lock(&philo->data->mwrite);
	printf("%ld philo %ld %s\n", philo->last_time, philo_n, mes);
}

void	take_fork(t_philo *philo)
{
	print_mes(philo, philo->n, "has taken a fork");
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	take_fork(philo);
	pthread_mutex_unlock(&philo->data->mwrite);
	return(NULL);
}

void	philosophers(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;

	if (args_not_valid(argc, argv))
		return (ft_error("Incorrect arguments"));
	if (init_all(&data, argc, argv))
		return (ft_error("Data can't be initialized"));
	philosophers(&data);
	pthread_mutex_destroy(&data.mwrite);

	free(data.philo);
	free(data.forks);
	return (0);
}
