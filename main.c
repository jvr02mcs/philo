#include "philo.h"

int	init_all(t_table *table, char **argv)
{
	if (!init_data(&table->data, argv))
		return (0);
	if (!init_forks(table))
		return (0);
	if (!init_philos(table))
	{
		return (0);
	}
	return (1);
}

//void	philosophers()
//{

//}

int	main(int argc, char **argv)
{
	t_table	table;

	if (args_not_valid(argc, argv))
		return (1);
	if (!init_all(&table, argv))
		return (1);
	//philosophers();	
	return (0);
}