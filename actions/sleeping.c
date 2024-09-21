#include "../philo.h"

void	sleeping(t_philo *philo)
{
	if (philo->data->end == 0 && philo->death == 0)
	{
		print_mes(philo, "is sleeping");
		if (philo->data->end == 0)
		{
			ft_sleepms(philo->data->t2sleep);
		}
	}
}
