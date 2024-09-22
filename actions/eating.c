#include "../philo.h"

void	eating(t_philo *philo)
{
	if (philo->data->end == 0 && philo->death == 0)
	{
		take_forks(philo);
		philo->eating = 1;
		philo->meals++;
		philo->last_meal = get_time() - philo->data->start_time;
		print_mes(philo, "is eating");
		if (philo->data->end == 0 && philo->death == 0)
		{
			ft_sleepms(philo->data->t2eat);
		}
		philo->eating = 0;
		leave_forks(philo);
	}
}
