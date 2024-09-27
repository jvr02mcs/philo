#include "philo.h"

static	int	arg_not_int(long n)
{
	return (n > INT_MAX || n < INT_MIN);
}

static	int	arg_not_digit(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && arg[i] == '+')
			i++;
		else
		{
			if ((arg[i] < '0' || arg[i] > '9'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	args_not_valid(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (printf("\033[0;31mInvalid number of args\n\033[0m"));
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0)
			return (printf("\033[0;31mInvalid args\n\033[0m"));
		if (arg_not_digit(argv[i]) || arg_not_int(ft_atol(argv[i])))
			return (printf("\033[0;31mInvalid args\n\033[0m"));
		if (i > 1 && ft_atol(argv[i]) < 1)
			return (printf("\033[0;31mInvalid time\n\033[0m"));
		i++;
	}
	return (0);
}
