#include "../philo.h"

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->mutex);
	philo->eating = 1;
	philo->last_meal = get_time();
	print_mes(philo, "is eating");
	philo->meals++;
	ft_sleepms(philo->data->t2eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->data->mutex);
	leave_forks(philo);
}
