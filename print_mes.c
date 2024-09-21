#include "philo.h"

void	print_mes(t_philo *philo, char *mes)
{
	int	cmp;

	pthread_mutex_lock(&philo->data->write_mtx);
	cmp = ft_strncmp(mes, "died", ft_strlen(mes));
	if (cmp == 0 && philo->data->end == 0)
	{
		printf("%zu %d %s\n", get_time() - philo->data->start_time, philo->n, mes);
		philo->data->end = 1;
	}
	if (philo->data->end == 0)
		printf("%zu %d %s\n", get_time() - philo->data->start_time, philo->n, mes);
	pthread_mutex_unlock(&philo->data->write_mtx);
}
