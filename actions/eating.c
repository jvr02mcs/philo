#include "../philo.h"

void	eating(t_philo *philo)
{
	if (philo->data->end == 0 && philo->death == 0)
	{
		take_forks(philo);
		// printf("%d eat\n", philo->n);
		pthread_mutex_lock(&philo->data->mutex);
		philo->eating = 1;
		philo->meals++;
// ntf("%d eat->2\n", philo->n);
		philo->last_meal = get_time() - philo->data->start_time;
		pthread_mutex_unlock(&philo->data->mutex);
		// printf("%d eat->3\n", philo->n);
		print_mes(philo, "is eating");
		if (philo->data->end == 0)
		{
			ft_sleepms(philo->data->t2eat);
		}
		philo->eating = 0;
		leave_forks(philo);
	}
}
