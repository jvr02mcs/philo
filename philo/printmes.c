/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:32:32 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/29 22:02:14 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    printmes(t_philo *philo, char *mes)
{
	if (!everyone_okey(philo))
		return ;
	pthread_mutex_lock(philo->write_mtx);
	printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->n, mes);
	pthread_mutex_unlock(philo->write_mtx);
}
