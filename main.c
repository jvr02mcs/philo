#include "philo.h"

t_times	asign_times(char **arg, int n)
{
	t_times time_to;

	time_to.die = ft_atol(arg[1]);
	time_to.eat = ft_atol(arg[2]);
	time_to.sleep = ft_atol(arg[3]);
	printf("n of philos: %d\n", n);
	if (n == 4)
		time_to.each = ft_atol(arg[4]);
	else
		time_to.each = 0;
	return (time_to);
}

void	*routine(void *arg)
{
	t_philo *p = (t_philo *)arg;  // Convertir el argumento en un puntero a t_program

	return (NULL);
}

int	ft_philo(t_program *p)
{
	size_t	i;

	i = 1;
	while (i < p->n_of_philos)
	{
		p->philos[i].n_of_the_philo = i;
		if (pthread_create(&p->philos[i].thread, NULL, &routine, &p->philos[i]) != 0)
			return (1);
		i++;
	}
	printf("%zu\n", i);
	while (i < p->n_of_philos)
	{
		if (pthread_join(p->philos[i].thread, NULL) != 0)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_program p;

	if (args_not_valid(argc, argv))
		return (1);
	p.n_of_philos = ft_atol(argv[1]);
	p.philos->time_to = asign_times(argv + 1, argc - 2);
	p.philos = malloc(sizeof(t_philo) * p.n_of_philos);
	if (ft_philo(&p) != 0)
		return (1);
	return (0);
}
