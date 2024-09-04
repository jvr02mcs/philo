#include "philo.h"

void	print_mes(t_data *d, size_t philo_n, char *mes)
{
	pthread_mutex_lock(&d->mwrite);
	printf("%ld philo %ld %s\n", get_time() - d->start_time, philo_n, mes);
	pthread_mutex_unlock(&d->mwrite);
}

void	take_fork(t_philo *philo)
{
	if (philo->n % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->l_fork].fork);
		print_mes(philo->data, philo->n, "has taken left fork");
		pthread_mutex_lock(&philo->data->m_thread);
		philo->data->forks[philo->l_fork].in_use = 1;
		pthread_mutex_unlock(&philo->data->m_thread);
		
		pthread_mutex_lock(&philo->data->forks[philo->r_fork].fork);
		print_mes(philo->data, philo->n, "has taken right fork");
		pthread_mutex_lock(&philo->data->m_thread);
		philo->data->forks[philo->r_fork].in_use = 1;
		pthread_mutex_unlock(&philo->data->m_thread);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->r_fork].fork);
		pthread_mutex_lock(&philo->data->m_thread);
		philo->data->forks[philo->r_fork].in_use = 1;
		pthread_mutex_unlock(&philo->data->m_thread);
		print_mes(philo->data, philo->n, "has taken right fork");
		
		pthread_mutex_lock(&philo->data->forks[philo->l_fork].fork);
		print_mes(philo->data, philo->n, "has taken left fork");
		pthread_mutex_lock(&philo->data->m_thread);
		philo->data->forks[philo->l_fork].in_use = 1;
		pthread_mutex_unlock(&philo->data->m_thread);
	}
}

void	eating(t_philo *philo)
{
	//t_fork	*forkk;

	//forkk = philo->data->forks;
	pthread_mutex_lock(&philo->eating);
	print_mes(philo->data, philo->n, "is eating");
	ft_msleep(philo->data->time_to.eat);
	pthread_mutex_unlock(&philo->eating);
}

void	sleeping(t_philo *philo)
{
	print_mes(philo->data, philo->n, "is sleeping");
	ft_msleep(philo->data->time_to.sleep);
}

void	thinking(t_philo *philo)
{
	print_mes(philo->data, philo->n, "is thinking");
}

void	leave_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork].fork);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork].fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_fork(philo);
		eating(philo);
		leave_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return(NULL);
}

void	philosophers(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data data;

	if (args_not_valid(argc, argv))
		return (ft_error("Incorrect arguments"));
	if (init_all(&data, argc, argv))
		return (ft_error("Data can't be initialized"));
	philosophers(&data);
	pthread_mutex_destroy(&data.mwrite);
	free(data.philo);
	free(data.forks);
	return (0);
}
