/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:53:48 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 21:13:13 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philos == 1)
	{
		printmes(philo, "has taken a fork");
		ft_sleepms(philo->data->t2die + 1);
		return (NULL);
	}
	philo->last_meal = get_time();
	if (philo->n % 2 == 0)
		ft_sleepms(philo->data->t2eat / 2);
	while (1)
	{
		if (!everyone_okey(philo))
			return (NULL);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
