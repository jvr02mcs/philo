/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:14 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 20:24:39 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_all(t_table *table, char **argv)
{
	if (!init_data(&table->data, argv))
		return (0);
	if (!init_forks(table))
		return (0);
	if (!init_philos(table))
	{
		free_forks(table, table->data.n_philos);
		pthread_mutex_destroy(&table->data.mtx);
		pthread_mutex_destroy(&table->write);
		return (0);
	}
	return (1);
}

void	philosophers(t_table *table)
{
	pthread_t	monitor_th;
	int	i;
	int	n;

	i = 0;
	n = table->data.n_philos;	
	pthread_create(&monitor_th, NULL, &monitor, table);
	table->data.start_time = get_time();
	while (i < n)
	{
		pthread_create(&table->philo[i].th, NULL, &routine, &table->philo[i]);
		i++;
	}
	pthread_join(monitor_th, NULL);
	i = 0;
	while (i < n)
	{
		pthread_join(table->philo[i].th, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (args_not_valid(argc, argv))
		return (1);
	if (!init_all(&table, argv))
		return (1);
	philosophers(&table);
	free_all(&table);
	return (0);
}
