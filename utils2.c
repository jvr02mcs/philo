#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleepms(size_t time2)
{
	size_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time2)
		usleep(time2 / 1000);
}