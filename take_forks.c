#include "philo.h"

// bloquear si puede o no si esta muerto etc...
static int	take_fork(t_philo *philo, size_t n)
{
	if (death_management(philo) || get_action(philo) == DEAD)
		return (1);
	pthread_mutex_lock(&philo->data->forks[n]);
	print_mes(philo->data, philo->n, "has taken a fork");
	return (0);
}

int	take_both_forks(t_philo *philo)
{
	if (philo->data->n_of_philos == 1)
		return (handle_one(philo));
	if (take_fork(philo, philo->l_fork))
		return (1);
	if (take_fork(philo, philo->r_fork))
	{
		leave_fork(&philo->data->forks[philo->l_fork]);
		return (1);
	}
	return (0);
}