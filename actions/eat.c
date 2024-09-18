#include "../philo.h"

int	eat(t_philo *philo)
{
	if (take_forks(philo))
	{
		if (philo_is_dead(philo))
		{
			pthread_mutex_unlock(philo->left);
			pthread_mutex_unlock(philo->right);
			return (0);
		}
		print_mes(philo->data, philo->n, "is eating");
		pthread_mutex();
	}
}