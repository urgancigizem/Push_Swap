NAME        = push_swap

SRCS_MAIN   = push_swap.c

SRCS        = check_funcs.c \
              error.c \
              free_funcs.c \
              sort_func.c \
              ft_add_back.c \
              ft_create_index.c \
              ft_new_stack.c \
              input_handlers.c \
              move_funcs.c \
              utils.c 

OBJS        = $(SRCS:.c=.o) $(SRCS_MAIN:.c=.o)

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
