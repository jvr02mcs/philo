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

void	*meals_check(void *arg)
{
	t_data	*data;
	
	data = (t_data *)arg;
	while (data->end == 0)
	{
		if (all_finished(data))
			data->end = 1;
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
		if (not_in_time(philo) && philo->eating == 0)
		{
			philo->death = 1;
			print_mes(philo, "died");
			//pthread_mutex_lock(&philo->data->write_mtx);
			//philo->data->end = 1;
			//pthread_mutex_unlock(&philo->data->write_mtx);
		}
	}
	//if (philo->meals == philo->data->meals4each)
	//{
	//	pthread_mutex_lock(&philo->data->mutex);
	//	philo->done++;
	//	pthread_mutex_unlock(&philo->data->mutex);
	//}
	return (NULL);
}
