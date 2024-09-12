#include "philo.h"

void	set_action(t_philo *philo, t_act action)
{
	pthread_mutex_lock(&philo->data->action_mutex);
	if (philo->action != DEAD)
		philo->action = action;
	pthread_mutex_unlock(&philo->data->action_mutex);
}

t_act	get_action(t_philo *philo)
{
	t_act	action;

	pthread_mutex_lock(&philo->data->action_mutex);
	action = philo->action;
	pthread_mutex_unlock(&philo->data->action_mutex);
	return (action);
}