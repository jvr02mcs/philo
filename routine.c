#include "philo.h"

void	sleeping(t_philo *philo, size_t time2)
{
	print_mes(philo->data, philo->n, "is sleeping");
	ft_sleep(time2);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
		ft_sleep(philo->data->t2eat);
	while (1)
	{
		if (eating(philo))
			return (NULL);
		sleeping(philo, philo->data->t2sleep);
	}
	return (NULL);
}