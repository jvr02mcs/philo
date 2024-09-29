/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:02 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/28 16:32:05 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_forks(t_table *table, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	free_all(t_table *table)
{
	free_forks(table, table->data.n_philos);
	free_philos_mutex(table, table->data.n_philos);
	pthread_mutex_destroy(&table->data.mtx);
	free(table->philo);
	pthread_mutex_destroy(&table->write);
}
