SRC = main.c\
	actions.c\
	args.c\
	forks.c\
	free.c\
	init.c\
	timecheck.c\
	mealscheck.c\
	printmes.c\
	routine.c\
	timeutils.c\
	utils.c\

CC = gcc
OBJS = $(SRC:.c=.o)
HEADERS = philo.h 
NAME = philo
FLAGS = -Wall -Wextra -Werror
#check data races : -g3  -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBRARYFLAG)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 
