#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time() - philo->data->start_time;
	pthread_create(&philo->check_th, NULL, check, philo);
	if(philo->n % 2 == 0)
		ft_sleepms(philo->data->t2eat/2);
	while (philo->data->end == 0)
	{
		eating(philo);
		sleeping(philo);
		print_mes(philo, "is thinking");
	}
	pthread_join(philo->check_th, NULL);
	return (NULL);
}
