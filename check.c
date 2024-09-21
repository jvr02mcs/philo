#include "philo.h"

static int	not_in_time(t_philo *philo)
{
	size_t actual;

	actual = get_time() - philo->data->start_time - philo->last_meal;
	//print_mes(philo->data, philo->n, "hola");
	//printf("\n%ld --> %ld - %d\n", actual, get_time() - philo->data->start_time , philo->last_meal);
	if (actual > philo->data->t2die)
		return (1);
	else
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
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->end == 0)
	{
		if (not_in_time(philo) && philo->eating == 0)
		{
			philo->death = 1;
			print_mes(philo, "died");
		}
		if (philo->meals == philo->data->meals4each)
		{
			pthread_mutex_lock(&philo->data->mutex);
			philo->done++;
			pthread_mutex_unlock(&philo->data->mutex);
		}
	}
	return (NULL);
}
