#include "philo.h"

int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(t_mutex) * table->data.n_philos);
	if (!table->forks)
		return (0);
	while (i < table->data.n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			free(table->forks);
			return (0);
		}
		i++;
	}
	return (1);
}
