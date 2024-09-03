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
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	print_mes(philo, philo->n, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	print_mes(philo, philo->n, "has taken a fork");
}

void	eating(t_philo *philo)
{
	usleep(philo->data->time_to.eat);
	philo->meals++;
	print_mes(philo, philo->n, "is eating");
	if (philo->meals > 0 && philo->meals == philo->data->time_to.meals4each)
	{
		//to_do : dead
	}
}

void	sleeping(t_philo *philo)
{
	usleep(philo->data->time_to.sleep);
	print_mes(philo, philo->n, "is sleeping");
}

void	thinking(t_philo *philo)
{
	print_mes(philo, philo->n, "is thinking");
}

void	leave_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_fork(philo);
	eating(philo);
	leave_fork(philo);
	sleeping(philo);
	thinking(philo);
	return(NULL);
}

void	philosophers(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->time_to.n_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->time_to.n_of_philos)
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
