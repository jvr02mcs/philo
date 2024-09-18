#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
		ft_sleep(1);
	while (philo->data->end == 0)
	{
		if (philo_is_dead(philo))
			return (NULL);
		//TAKE FORKS
		if (take_forks(philo))
			eat();
		if (philo_is_dead(philo))
		{
			//LEAVE FORKS
			return (NULL);
		}
		//EAT
		if (philo_is_dead(philo))
			return (NULL);
		//SLEEP
		if (philo_is_dead(philo))
			return (NULL);
		//THINK
	}
	return (NULL);
}
