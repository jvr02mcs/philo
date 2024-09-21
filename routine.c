#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time() - philo->data->start_time;
	if(philo->n % 2 == 0)
		ft_sleepms(philo->data->t2eat / 2);
	while (philo->data->end == 0)
	{
		eating(philo);
		sleeping(philo);
		if (philo->data->end == 0 && philo->death == 0)
			print_mes(philo, "is thinking");
		// printf("%d routine\n", philo->n);
	}
	return (NULL);
}

