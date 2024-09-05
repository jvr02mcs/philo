#include "philo.h"

void	print_mes(t_data *d, size_t philo_n, char *mes)
{
	pthread_mutex_lock(&d->mwrite);
	printf("%ld philo %ld %s\n", get_time() - d->start_time, philo_n, mes);
	pthread_mutex_unlock(&d->mwrite);
}

void	take_fork(t_philo *philo)
{
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
		print_mes(philo->data, philo->n, "has taken left fork");
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
		print_mes(philo->data, philo->n, "has taken right fork");
}

void	eating(t_philo *philo)
{
	//t_fork	*forkk;

	//forkk = philo->data->forks;
	pthread_mutex_lock(&philo->eating);
	philo->meals++;
	philo->last_time = get_time() - philo->data->start_time;
	print_mes(philo->data, philo->n, "is eating");
	pthread_mutex_unlock(&philo->eating);
	ft_msleep(philo->data->time_to.eat);
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
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

int	death(t_philo *philo, size_t meals4each)
{
	size_t	curr;

	
	curr = (get_time() - philo->data->start_time);
	if (curr - philo->last_time > philo->data->time_to.die)
	{
		print_mes(philo->data, philo->n, "died");
		if (meals4each == 0)
		{
			pthread_mutex_lock(&philo->data->mwrite);
			philo->data->end = 1;
			pthread_mutex_unlock(&philo->data->mwrite);
			return (1);
		}
	}
	if (meals4each > 0)
	{
		if (philo->meals < meals4each)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!death(philo, philo->data->meals4each))
	{
		if (philo->n % 2 != 0)
			ft_msleep(philo->data->time_to.eat / 2);
		take_fork(philo);
		eating(philo);
		leave_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return(NULL);
}

//void	*monitor(void *arg)
//{
//	t_data	*data;
//	size_t	i;

//	i = 0;
//	data = (t_data *)arg;
//	while (i < data->n_of_philos)
//		printf("%ld\n", data->philo[i++].meals);
//	return (NULL);
//}

void	philosophers(t_data *data)
{
	size_t	i;

	i = 0;
	//pthread_create(&data->m_thread, NULL, &monitor, &data);
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
	//pthread_join(data->m_thread, NULL);
}

void	destroy_forks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
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
	destroy_forks(&data);
	pthread_mutex_destroy(&data.mwrite);
	free(data.philo);
	free(data.forks);
	return (0);
}
