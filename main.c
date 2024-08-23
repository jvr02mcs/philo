#include "philo.h"

//void	*routine(void *arg)
//{
//	return (NULL);
//}

//int	ft_philo(t_data *p)
//{
//}

int main(int argc, char **argv)
{
	t_data data;

	if (args_not_valid(argc, argv))
		return (ft_error("Incorrect arguments"));
	if (init_all(&data, argc, argv))
		return (1);
	free(data.philo);
	free(data.forks);
	//if (ft_philo(&data) != 0)
	//	return (1);
	return (0);
}
