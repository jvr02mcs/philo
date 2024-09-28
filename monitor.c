#include "philo.h"

void	*monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	int i;
	
	i = 0;
	while (i < table->data.n_philos)
	{
		if (get_time() - table->data.start_time - table->philo[i].last_meal > table->data.t2die)
			//die
		i++;
	}
	return (NULL);
}