#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
		ft_sleepms(philo->data->t2eat / 2);
	while (philo->data->end == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		// printf("%d routine\n", philo->n);
	}
	return (NULL);
}

