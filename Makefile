

NAME		= push_swap

SRCS_MAIN	= push_swap.c

SRCS 		= check_funcs.c\
			  error.c\
			  free_funcs.c\
			  sort_func.c\
			  ft_add_back.c\
			  ft_create_index.c\
			  ft_new_stack.c\
			  input_handlers.c\
			  move_funcs.c\

LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

OBJS_MAIN	= $(SRCS_MAIN:.c=.o) $(SRCS:.c=.o)

$(NAME): $(OBJS_MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_MAIN) -lft -L$(LIBFT_DIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

all: $(NAME)

clean:
	make -s -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_MAIN) 

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 