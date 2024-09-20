#include "../philo.h"

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->mutex);
	philo->eating = 1;
	philo->meals++;
	philo->last_meal = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->mutex);
	print_mes(philo, "is eating");
	ft_sleepms(philo->data->t2eat);
	philo->eating = 0;
	leave_forks(philo);
}
