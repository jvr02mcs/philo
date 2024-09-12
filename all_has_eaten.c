#include "philo.h"

int	handle_one(t_philo *philo)
{
	set_action(philo, DEAD);
	set_flag(philo->data, 0);
	print_mes(philo->data, philo->n, "died");
	return (1);
}

int	all_philos_has_eaten(t_data	*data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		if (data->meals4each > data->philo[i].meals)
			return (0);
		i++;
	}
	return (1);
}
