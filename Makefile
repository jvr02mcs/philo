GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m
SRC = main.c\
	init.c\
	utils.c\
	error.c\
	parser.c\
	ft_atol.c\
	asign_times.c\
	mutex_action.c\

OBJS = $(SRC:.c=.o)
HEADERS = philo.h 
NAME = philo
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "$(GREEN)philo compiled!$(NC)"

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME):
	@echo "$(YELLOW)"
	@pid=$$! ; \
	total=50 ; \
	i=0 ; \
	while [ $$i -le $$total ]; do \
		sleep 0.05 ; \
		i=$$(($$i + 1)) ; \
		percent=$$(($$i * 100 / ($$total + 1))) ; \
		printf "\rCompiling philo ... %3d%%" "$$percent" ; \
	done ; \
	wait $$pid ; \

	@echo "$(NC)"
	@gcc $(FLAGS) -o $(NAME) $(SRC)
clean:
	
	@echo "$(RED)"
	rm -f $(OBJS)
	@echo "$(GREEN)philo cleaned!$(NC)"

fclean: clean
	@echo "$(RED)"
	rm -f $(NAME)
	@echo "$(GREEN)fclean done!$(NC)"
	
re: fclean all

.PHONY: all clean fclean re 