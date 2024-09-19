#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->death = get_time() + philo->data->t2die;
	pthread_create(&philo->check_th, NULL, check, philo);
	while (philo->data->end == 0)
	{
		eating(philo);
		sleeping(philo);
		print_mes(philo, "is thinking");
	}
	pthread_join(philo->check_th, NULL);
	return (NULL);
}
