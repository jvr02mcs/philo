#include "philo.h"

void	set_last_meal(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lm_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&data->lm_mutex);
}

size_t	get_last_meal(t_data *data, t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&data->lm_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&data->lm_mutex);
	return (last_meal);
}
