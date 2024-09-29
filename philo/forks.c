/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:31:50 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 21:13:21 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	take_forks(t_philo *philo)
{
	if (!everyone_okey(philo))
		return (0);
	pthread_mutex_lock(philo->left);
	printmes(philo, "has taken l fork");
	pthread_mutex_lock(philo->right);
	printmes(philo, "has taken r fork");
	return (1);
	return (1);
}
