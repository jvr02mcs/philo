#include "philo.h"

//separate first and second fork

int	take_forks(t_philo *philo)
{
	if (philo->n % 2 == 0)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
	if (philo_is_dead(philo) == 0)
		print_mes(philo->data, philo->n, "has taken a fork");
	if (philo->n % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left) != 0)
		{
			pthread_mutex_unlock(philo->right);
			return (0);
		}
		if (!philo_is_dead(philo))
			print_mes(philo->data, philo->n, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->right) != 0)
		{
			pthread_mutex_unlock(philo->left);
			return (0);
		}
		if (!philo_is_dead(philo))
			print_mes(philo->data, philo->n, "has taken a fork");
	}
	return (1);
}
