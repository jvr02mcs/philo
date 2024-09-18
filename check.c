#include "philo.h"

static int	not_in_time(t_philo *philo)
{
	if (get_time() - philo->data->start_time > philo->data->t2die)
	{
		philo->data->end = 1;
		print_mes(philo->data, philo->n, "died");
		return (1);
	}
	else
		return (0);
}

static int	one_philo_dies(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n_philos)
	{
		if (not_in_time(&d->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->end == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (0);
}

void	*check(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (one_philo_dies(data))
		{
			usleep(100);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}
