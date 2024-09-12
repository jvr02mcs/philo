#include "philo.h"

int	eating(t_philo *philo)
{
	if (take_both_forks(philo))
		return (1);
	pthread_mutex_lock(&philo->data->eating_mutex);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->eating_mutex);
	set_last_meal(philo->data, philo);
	print_mes(philo->data, philo->n, "is eating");
	ft_msleep(philo->data->time_to.eat);
	leave_both_forks(philo);
	pthread_mutex_lock(&philo->data->mwrite);
	pthread_mutex_unlock(&philo->data->mwrite);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo->action == DEAD)
		return (1);
	set_action(philo, SLEEPING);
	print_mes(philo->data, philo->n, "is sleeping");
	ft_msleep(philo->data->time_to.sleep);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo->action == DEAD)
		return (1);
	set_action(philo, THINKING);
	print_mes(philo->data, philo->n, "is thinking");
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 != 0)
		ft_msleep(philo->data->time_to.eat);
	while (get_action(philo) != DEAD)
	{
		if (eating(philo))
			break;
		if (get_action(philo) == DEAD)
			break;
		if (sleeping(philo))
			break;
		if (thinking(philo))
			break;
	}
	return(NULL);
}
