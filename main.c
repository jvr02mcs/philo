#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (args_not_valid(argc, argv))
		return (1);
	if (init_data(&data, argc, argv))
		return (1);
	philosophers(&data);
	destroy_data(&data);
	return (0);
}
