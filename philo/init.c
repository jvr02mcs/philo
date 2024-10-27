/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:07 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 21:09:05 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		data->meals4each = -1;
	data->start_time = 0;
	data->someone_dead = 0;
	return (1);
}

int	init_mutex(t_table *table, t_philo *philo)
{
	philo->write_mtx = &table->write;
	if (pthread_mutex_init(&philo->eating_mtx, NULL) != 0)
		return (0);
	return (1);
}

//probar con i + 1 % n

void	asign_fork(t_table *table, int i)
{
	int	n;

	n = table->data.n_philos;
	table->philo[i].right = &table->forks[i];
	if (n == 1)
		table->philo[i].left = NULL;
	else if (i == 0)
		table->philo[i].left = &table->forks[n - 1];
	else
		table->philo[i].left = &table->forks[i - 1];
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
		if (!init_mutex(table, &table->philo[i]))
		{
			free_philos_mutex(table, i);
			free(table->philo);
			free_forks(table, table->data.n_philos);
			return (0);
		}
		table->philo[i].n = i + 1;
		table->philo[i].meals = 0;
		table->philo[i].data = &table->data;
		table->philo[i].last_meal = get_time();
		asign_fork(table, i);
		i++;
	}
	return (1);
}
