#include "philo.h"

int	mutex_action(t_mutex *mutex, int f)
{
	if (f == 0)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (1);
	}
	else if (f == 1)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (2);	
	}
	else if (f == 2)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (3);
	}
	else if (f == -1)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (4);
	}
	return (0);
}
