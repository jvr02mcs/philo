#include "philo.h"

static void	leave_fork(t_mutex *fork, int hand)
{
	pthread_mutex_unlock(&fork[hand]);
}

static int	take_fork(t_mutex *fork, int hand)
{
	if (pthread_mutex_lock(&fork[hand]))
		return (1);
	return (0);
}

static int	take_both_forks(t_philo *philo)
{
	if (take_fork(philo->data->forks, philo->left))
		return (1);
	print_mes(philo->data, philo->n, "has taken a fork");
	if (take_fork(philo->data->forks, philo->right))
	{
		leave_fork(philo->data->forks, philo->left);
		return (1);
	}
	print_mes(philo->data, philo->n, "has taken a fork");
	return (0);
}

int	eating(t_philo *philo)
{
	if (take_both_forks(philo))
		return (1);
	print_mes(philo->data, philo->n, "is eating");
	ft_sleep(philo->data->t2eat);
	leave_fork(philo->data->forks, philo->left);
	leave_fork(philo->data->forks, philo->right);
	return (0);
}