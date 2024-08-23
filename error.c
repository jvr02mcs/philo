#include "philo.h"

int	ft_error(char *error)
{
	printf("\033[0;31mError : \033[0m%s\n", error);
	return (1);
}
int	ft_error_in_mutex(int error, int w)
{
	if (error == 1)
		printf("Mutex in while %d can't be unlocked", w);
	else if (error == 2)
		printf("Mutex in while %d can't be locked", w);
	else if (error == 3)
		printf("Mutex in while %d can't be initialiced", w);
	else if (error == 4)
		printf("Mutex in while %d can't be destroyed", w);
	return (1);
}