#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	if (pthread_mutex_init(&data->mtx, NULL) != 0)
		return (0);
	data->n_philos = ft_atoi(argv[1]);
	data->t2die = ft_atoi(argv[2]);
	data->t2eat = ft_atoi(argv[3]);
	data->t2sleep = ft_atoi(argv[4]);
	if (argv[5] && ft_atoi(argv[5]) > 0)
		data->meals4each = ft_atoi(argv[5]);
	else
		data->meals4each = 0;
	data->start_time = get_time();
	return (1);
}


int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->data.n_philos);
	if (!table->philo)
		return (0);
	while (i < table->data.n_philos)
	{
		table->philo[i].n = i + 1;
		table->philo[i].meals = 0;
		table->philo[i].write_mtx = &table->write;
		if (table->philo[i].meals == 0)
		{ 
			free(table->philo);
			return (free_forks(table), 0);
		}
		table->philo[i].data = &table->data;
		table->philo[i].last_meal = get_time();
		//assign_fork(program, i);
		i++;
	}
	return (1);
}
