#include "philo.h"

int	not_in_time(t_philo *philo)
{
	size_t actual;

	actual = get_time() - philo->data->start_time - philo->last_meal;
	if (actual > philo->data->t2die)
		return (1);
	else
		return (0);
}

int all_finished(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (data->philos[i].done == 0)
			return (0);
		i++;
	}
	return (1);
}
int	one_philo_is_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		//printf("\n%ld\n", data->philos[i].death);
		if (data->philos[i].death == 1)
			return (1);
		i++;
	}
	return (0);	
}

void	*time_check(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	while (data->end == 0)
	{
		if (one_philo_is_death(data))
		{
			pthread_mutex_lock(&data->mutex);
			data->end = 1;
			pthread_mutex_lock(&data->mutex);
		}
		usleep(100);
	}
	return (NULL);
}
void	*meals_check(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	while (data->end == 0)
	{
		if (all_finished(data))
		{
			pthread_mutex_lock(&data->mutex);
			data->end = 1;
			pthread_mutex_unlock(&data->mutex);
		}
		usleep(100);
	}
	return (NULL);
}

void	*check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->end == 0 && philo->death == 0)
	{
		//if (not_in_time(philo) && philo->eating == 0)
		//{
		//	print_mes(philo, "died");
		//	pthread_mutex_lock(&philo->data->mutex);
		//	philo->data->end = 1;
		//	pthread_mutex_unlock(&philo->data->mutex);
		//}
		if (philo->meals == philo->data->meals4each)
		{
			pthread_mutex_lock(&philo->data->mutex);
			philo->done++;
			pthread_mutex_unlock(&philo->data->mutex);
		}
	}
	return (NULL);
}
