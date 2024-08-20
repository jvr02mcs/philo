# ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atol(const char *str);
size_t ft_strlen(char *s);

#endif