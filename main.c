#include "philo.h"

void	print_mes(t_data *d, size_t philo_n, char *mes)
{
	pthread_mutex_lock(&d->mwrite);
	printf("%ld philo %ld %s\n", get_time() - d->start_time, philo_n, mes);
	//if (mes[0] != 'd')
		pthread_mutex_unlock(&d->mwrite);
}

void	take_fork(t_philo *philo)
{
	if (philo->is_dead == 0 && philo->data->end == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
		print_mes(philo->data, philo->n, "has taken left fork");
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
		print_mes(philo->data, philo->n, "has taken right fork");
	}
}

void	leave_fork(t_philo *philo)
{
	if (philo->is_dead == 0 && philo->data->end == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	}
}

void	eating(t_philo *philo)
{
	//t_fork	*forkk;

	//forkk = philo->data->forks;
	if (philo->is_dead == 0 && philo->data->end == 0)
	{
		pthread_mutex_lock(&philo->eating);
		philo->meals++;
		philo->last_time = get_time() - philo->data->start_time;
		print_mes(philo->data, philo->n, "is eating");
		pthread_mutex_unlock(&philo->eating);
		ft_msleep(philo->data->time_to.eat);
	}
}

void	sleeping(t_philo *philo)
{
	if (philo->is_dead == 0 && philo->data->end == 0)
	{
		print_mes(philo->data, philo->n, "is sleeping");
		ft_msleep(philo->data->time_to.sleep);
	}
}

void	thinking(t_philo *philo)
{
	if (philo->is_dead == 0 && philo->data->end == 0)
		print_mes(philo->data, philo->n, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->end == 0)
	{
		if (philo->data->meals4each > 0 && philo->data->philo->meals >= philo->data->meals4each)
		{
			pthread_mutex_lock(&philo->data->mwrite);
			philo->data->end = 1;
			pthread_mutex_unlock(&philo->data->mwrite);
			break;
		}
		if (philo->n % 2 != 0)
			ft_msleep(philo->data->time_to.eat / 2);
		take_fork(philo);
		eating(philo);
		leave_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	printf("hola %ld\n", philo->n);
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
