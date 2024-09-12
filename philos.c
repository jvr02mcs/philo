#include "philo.h"

static void	threads_create(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->meals4each > 0)
		pthread_create(&data->th_check_meals, NULL, &check_meals, &data);
	pthread_create(&data->th_check_time, NULL, &check_time, &data);
	while (i < data->n_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
		ft_msleep(1);
	}
}

static void	threads_join(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(data->th_check_time, NULL);	
	if (data->meals4each > 0)
		pthread_join(data->th_check_meals, NULL);	
}

void	philosophers(t_data *data)
{
	threads_create(data);
	threads_join(data);
}