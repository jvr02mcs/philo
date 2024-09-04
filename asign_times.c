#include "philo.h"

t_times	asign_times(char **arg)
{
	t_times	time_to;

	time_to.die = ft_atol(arg[2]);
	time_to.eat = ft_atol(arg[3]);
	time_to.sleep = ft_atol(arg[4]);
	return (time_to);
}
