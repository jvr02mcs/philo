#include "philo.h"

int arg_not_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && arg[i] == '+')
			i++;
		else
		{
			if (arg[i] == '-')
				return (1);
			if ((arg[i] < '0' || arg[i] > '9'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	args_not_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc - 1 != 4 && argc - 1 != 5)
	{
		printf("c = %d\n", argc - 1);
		return (1);
	}
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "", ft_strlen(argv[i])) == 0)
			return (2);
		if (arg_not_digit(argv[i]))
			return (3);
		i++;
	}
	return (0);	
}

int main(int argc, char **argv)
{
	if (args_not_valid(argc, argv))
		return (1);
	return (0);

}