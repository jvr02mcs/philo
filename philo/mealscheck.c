#include "philo.h"

int	everyone_eaten(t_table *table, int n)
{
	int	i;
	int	done;
	
	i = 0;
	done = 0;
	if (table->data.meals4each == -1)
		return (0);
	while (i < n)
	{
		pthread_mutex_lock(&table->philo[i].eating_mtx);
		if (table->philo[i].meals >= table->data.meals4each)
			done++;
		pthread_mutex_unlock(&table->philo[i].eating_mtx);
		i++;
	}
	if (done == n)
		return (1);
	return (0);
}

void	*meals_check(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (!someone_is_dead(&table->data))
	{
		if (everyone_eaten(table, table->data.n_philos))
		{
			pthread_mutex_lock(&table->data.mtx);
			table->data.someone_dead = 1;
			pthread_mutex_unlock(&table->data.mtx);
			break ;
		}
	}
	return (NULL);
}