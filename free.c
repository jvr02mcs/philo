#include "philo.h"

void	free_mutex(t_mutex *mtx)
{
	pthread_mutex_destroy(mtx);
}

void	free_philos_mutex(t_table *table, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&table->philo[i].death_mtx);
		pthread_mutex_destroy(&table->philo[i].eating_mtx);
		i++;
	}
}


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