#include "philo.h"

//static int	not_in_time(t_philo *philo)
//{
//	size_t actual;

//	actual = get_time() - philo->data->start_time - philo->last_meal;
//	//print_mes(philo->data, philo->n, "hola");
//	//printf("\n%ld --> %ld - %d\n", actual, get_time() - philo->data->start_time , philo->last_meal);
//	if (actual > philo->data->t2die)
//		return (1);
//	else
//		return (0);
//}

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
	t_data	*data;
	t_philo	*philo;
	int		i;

	data = (t_data *)arg;
	philo = data->philos;
	while (data->end == 0)
	{
		i = 0;
		while (i < data->n_philos)
		{
			if (get_time() - philo->data->start_time - philo->last_meal > data->t2die && philo[i].eating == 0)
			{
				philo[i].death = 1;
				print_mes(&philo[i], "died");
			}
			if (philo[i].meals == data->meals4each)
			{
				pthread_mutex_lock(&data->mutex);
				philo[i].done++;
				pthread_mutex_unlock(&data->mutex);
			}
			i++;
		}
	}
	return (NULL);
}
