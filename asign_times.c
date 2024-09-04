#include "philo.h"

t_times	asign_times(char **arg, int n)
{
	t_times	time_to;

	time_to.die = ft_atol(arg[1]);
	time_to.eat = ft_atol(arg[2]);
	time_to.sleep = ft_atol(arg[3]);
	if (n == 4)
		time_to.meals4each = ft_atol(arg[4]);
	else
		time_to.meals4each = 1;
	return (time_to);
}
