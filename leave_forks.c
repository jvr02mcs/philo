#include "philo.h"

void	leave_fork(t_mutex *fork_mutex)
{
	pthread_mutex_unlock(fork_mutex);
}

void	leave_both_forks(t_philo *philo)
{
	leave_fork(&philo->data->forks[philo->l_fork]);
	leave_fork(&philo->data->forks[philo->r_fork]);
}