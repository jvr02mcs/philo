/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:23:21 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:24 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (!take_forks(philo))
		return ;
	pthread_mutex_lock(&philo->eating_mtx);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->eating_mtx);
	printmes(philo, "is eating");
	ft_sleepms(philo->data->t2eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping(t_philo *philo)
{
	printmes(philo, "is sleeping");
	ft_sleepms(philo->data->t2sleep);
}

void	thinking(t_philo *philo)
{
	printmes(philo, "is thinking");
}
