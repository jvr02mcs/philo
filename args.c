#include "philo.h"

static int	arg_not_int(long n)
{
	return (n > INT_MAX || n < INT_MIN);
}

static int	arg_not_digit(char *arg)
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
		return (1);
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0)
			return (1);
		if (arg_not_digit(argv[i]) || arg_not_int(ft_atol(argv[i])))
			return (1);
		i++;
	}
	return (0);
}
