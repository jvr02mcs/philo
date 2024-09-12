#include "philo.h"

int	death_management(t_philo *philo)
{
	//printf("%ld\n", current - get_last_meal(philo->data, philo));
	if (get_last_meal(philo->data, philo) == 0)
		return (0);
	if (get_time() - get_last_meal(philo->data, philo) > philo->data->time_to.die && get_action(philo) != EATING)
	{
		set_action(philo, DEAD);
		return (1);
	}
	return (0);
}

static void	set_all_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		set_action(&data->philo[i], DEAD);
		i++;
	}
}
void	*check_time(void *arg)
{
	t_data	**data;
	t_philo *philo;
	size_t	i;

	i = 0;
	data = (t_data **)arg;
	philo = (*data)->philo;
	ft_msleep((*data)->time_to.eat);
	while (i < (*data)->n_of_philos && get_flag((*data)))
	{
		if (death_management(philo) && get_action(&philo[i]) != EATING)
		{
			print_mes((*data), philo[i].n, "died");
			set_flag((*data), 0);
			set_all_philos((*data));
			break;
		}
		i++;
		if (i == (*data)->n_of_philos)
			i = 0;
	}
	return (NULL);
}

void	*check_meals(void *arg)
{
	t_data	**data;
	size_t	i;

	data = (t_data **)arg;
	i = 0;
	while (i < (*data)->n_of_philos && get_flag((*data)))
	{
		i++;
		if (i == (*data)->n_of_philos)
			i = 0;
	}
	return (NULL);
}
