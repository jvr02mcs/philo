#include "philo.h"

static void	create_threads(t_data *data)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = data->philos;
	while (i < data->n_philos)
	{
		pthread_create(&philo[i].th, NULL, &routine, &philo[i]);
		i++;
	}
}

static void	join_threads(t_data *data)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = data->philos;
	while (i < data->n_philos)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
}

void	philosophers(t_data *data)
{
	create_threads(data);
	join_threads(data);
}