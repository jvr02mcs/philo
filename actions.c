#include "philo.h"

void	eating(t_philo *philo)
{
	if (!take_forks(philo))
		return;
	printmes(philo, "is eating");
	ft_sleepms(philo->data->t2eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}
void	sleeping(t_philo *philo)
{
	printmes(philo, "is sleeping");
	ft_sleepms(philo->data->t2sleep);
}

void	thinking(t_philo *philo)
{
	printmes(philo, "is thinking");
}
