#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;

	if (args_not_valid(argc, argv))
		return (ft_error("Incorrect arguments"));
	if (init_all(&data, argc, argv))
		return (ft_error("Data can't be initialized"));
	free(data.philo);
	free(data.forks);
	return (0);
}
