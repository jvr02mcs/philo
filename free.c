#include"philo.h"

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->data.n_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}