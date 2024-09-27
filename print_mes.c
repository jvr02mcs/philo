#include "philo.h"

void	print_mes(t_philo *philo, char *mes)
{
	pthread_mutex_lock(&philo->data->write_mtx);
	if (philo->data->end == 0)
		printf("%zu %d %s\n", get_time() - philo->data->start_time, philo->n, mes);
	if(ft_strncmp(mes, "died", ft_strlen(mes)) != 0)
		pthread_mutex_unlock(&philo->data->write_mtx);
}
