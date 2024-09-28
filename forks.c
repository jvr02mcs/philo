#include "philo.h"
//liberar como en philo
int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&table->write, NULL) != 0)
		return (0);
	table->forks = malloc(sizeof(t_mutex) * table->data.n_philos);
	if (!table->forks)
		return (0);
	while (i < table->data.n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			free_forks(table, i);
			return (0);
		}
		i++;
	}
	return (1);
}
