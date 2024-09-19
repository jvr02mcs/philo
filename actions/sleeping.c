#include "../philo.h"

void	sleeping(t_philo *philo)
{
	print_mes(philo, "is sleeping");
	ft_sleepms(philo->data->t2sleep);
}