#include "../philo.h"

void	thinking(t_philo *philo)
{
	if (philo->data->end == 0 && philo->death == 0)
		print_mes(philo, "is thinking");
}