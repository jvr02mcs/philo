#include "philo.h"

void	print_mes(t_philo *philo, size_t philo_n, char *mes)
{
	pthread_mutex_lock(&philo->data->mwrite);
	philo->last_time = get_time();
	printf("%ld philo %ld %s\n", philo->last_time, philo_n, mes);
	pthread_mutex_unlock(&philo->data->mwrite);
}

void	take_fork(t_philo *philo)
{
	if (philo->n % 2 == 0)
	{
		if (philo->l_fork >= 0)
		{
			pthread_mutex_lock(&philo->data->forks[philo->l_fork].fork);
			print_mes(philo, philo->n, "has taken left fork");
		}
			pthread_mutex_lock(&philo->data->forks[philo->r_fork].fork);
			print_mes(philo, philo->n, "has taken right fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->r_fork].fork);
		print_mes(philo, philo->n, "has taken right fork");
		if (philo->l_fork >= 0)
		{
			pthread_mutex_lock(&philo->data->forks[philo->l_fork].fork);
			print_mes(philo, philo->n, "has taken left fork");
		}
	}
}

void	ft_msleep(size_t usec)
{
	usleep(usec * 1000);
}
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	pthread_mutex_lock(&philo->data->mwrite);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->mwrite);
	print_mes(philo, philo->n, "is eating");
	philo->last_time = get_time();
	ft_msleep(philo->data->time_to.eat);
	pthread_mutex_unlock(&philo->eating);
}

void	sleeping(t_philo *philo)
{
	print_mes(philo, philo->n, "is sleeping");
	ft_msleep(philo->data->time_to.sleep);
}

void	thinking(t_philo *philo)
{
	print_mes(philo, philo->n, "is thinking");
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
	while (philo->meals < philo->data->time_to.meals4each)
	{
		take_fork(philo);
		eating(philo);
		leave_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return(NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		while (i < data->n_of_philos)
		{
			if (data->philo[i].is_dead)
			{
				print_mes(&data->philo[i], data->philo[i].n, "died");
				return (NULL);
			}
			i++;
		}
	}
	usleep(1000);
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
