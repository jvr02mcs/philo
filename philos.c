#include "philo.h"

static void	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = data->philos;
	data->start_time = get_time();
	//pthread_create(&data->meals_th, NULL, meals_check, data);
	while (i < data->n_philos)
	{
		pthread_create(&philo[i].time_th, NULL, check, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&philo[i].th, NULL, &routine, &philo[i]);
		i++;
	}
}

static void	join_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = data->philos;
	while (i < data->n_philos)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(philo[i].time_th, NULL);
		i++;
	}
	//pthread_join(data->meals_th, NULL);
}

void	philosophers(t_data *data)
{
	create_threads(data);
	join_threads(data);
}
