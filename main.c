#include "philo.h"

t_times	asign_times(char **arg, int n)
{
	t_times time_to;

	time_to.die = ft_atol(arg[1]);
	time_to.eat = ft_atol(arg[2]);
	time_to.sleep = ft_atol(arg[3]);
	if (n == 4)
		time_to.each = ft_atol(arg[4]);
	else
		time_to.each = -1;
	return (time_to);
}

void	*routine(t_times t)
{
	//t_times *t = (t_times *)arg;  // Convertir el puntero void a t_program *
    //t_program aux = *p;
	printf("%ld, %ld, %ld\n", t.die, t.eat, t.sleep);
	return (NULL);
}

int	ft_philo(t_program p)
{
	size_t	i;

	i = 0;
	//while (i < p.n_of_philos)
	//{
	if (pthread_create(&p.philos[i].thread, NULL, routine(p.times_to), NULL) != 0)
		return (1);
	if (pthread_join(p.philos[i].thread, NULL) != 0)
		return (1);
	//}
	return (0);
}

int main(int argc, char **argv)
{
	t_program p;

	if (args_not_valid(argc, argv))
		return (1);
	p.n_of_philos = ft_atol(argv[1]);
	p.times_to = asign_times(argv + 1, argc - 2);
	if (ft_philo(p) != 0)
		return (1);
	return (0);
}
