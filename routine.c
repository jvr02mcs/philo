/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:53:48 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/28 16:53:51 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	//if (philo->data.n_philos == 1)
	//{
	//	return (NULL);
	//}
	int i = 0;
	philo->data->start_time = get_time();
	if (philo->n % 2 == 0)
		ft_sleepms(philo->data->t2eat / 2);
	while (i < 2)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	i++;
	}
	return (NULL);
}