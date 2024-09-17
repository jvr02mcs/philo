#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
		ft_sleep(1);
	while (philo->meals < philo->data->meals4each)
	{
		if (eating(philo))
			return (NULL);
	}
	return (NULL);
}