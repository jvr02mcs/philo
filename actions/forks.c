#include "../philo.h"

void leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_mes(philo, "has taken left fork");
	pthread_mutex_lock(philo->right);
	print_mes(philo, "has taken right fork");
}
