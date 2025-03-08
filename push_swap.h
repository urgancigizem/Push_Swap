#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>


# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack
{
	int        content;
    int    index;
    struct t_stack	*next;
}					t_stack;

t_stack *ft_new_stack(int content);
t_stack *ft_create_index(t_stack *a);
t_stack *main_input_handlers(int argc,char **argv);

int	ft_check_for_dup(t_stack *a);
int ft_check_for_sort(t_stack *a);
int	max_min_check(long long int number);
int	valid_check(const char *arg);

void swap(char *str,t_stack *stack);
void push (char *str,t_stack **dest,t_stack **src);
void rotate(char *str,t_stack **stack);
void reverse_rotate(char *str,t_stack **stack);
void sort_for_three (t_stack **a);
void    sort_for_four(t_stack **a, t_stack **b);
void	sort_for_five(t_stack **a, t_stack **b);
void radix_sort (t_stack **a,t_stack **b);
void ft_error(void);
void	ft_free_for_str(char **lst);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
void	ft_free_for_stack(t_stack *lst);
long	ft_atol(const char *str);
unsigned int	ft_stsize(t_stack *st);
t_stack	*ft_last(t_stack *st);
char	**ft_split(const char *str);
void	ft_putendl_fd(char *s, int fd);


#endif