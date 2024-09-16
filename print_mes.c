#include "philo.h"

void	print_mes(t_data *d, size_t philo_n, char *mes)
{
	pthread_mutex_lock(&d->write_mtx);
	printf("%ld %ld %s\n", get_time() - d->start_time, philo_n, mes);
	pthread_mutex_unlock(&d->write_mtx);
}
