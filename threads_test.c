#include <pthread.h>
#include <stdio.h>

void	*print_message(void *arg)
{
	char *message;

	message = (char *)arg;
	printf("%s\n", message);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread;
	char		*mes;

	mes = "hiloss!!";
	pthread_create(&thread, NULL, print_message, (void *)mes);
	pthread_join(thread, NULL);
	return(0);
}