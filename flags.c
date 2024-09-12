#include "philo.h"

void	set_flag(t_data *data, int flag)
{
	pthread_mutex_lock(&data->iter_mutex);
	data->end = flag;
	pthread_mutex_unlock(&data->iter_mutex);
}

int get_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->iter_mutex);
	flag = data->end;
	pthread_mutex_unlock(&data->iter_mutex);
	return (flag);
}