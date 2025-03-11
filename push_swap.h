/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:50 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 17:14:03 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				content;
	int				index;
	struct t_stack	*next;
}					t_stack;

t_stack				*ft_new_stack(int content);
t_stack				*ft_create_index(t_stack *a);
t_stack				*main_input_handlers(int argc, char **argv);
t_stack				*ft_last(t_stack *st);

int					ft_check_for_dup(t_stack *a);
int					ft_check_for_sort(t_stack *a);
int					max_min_check(long long int number);
int					valid_check(const char *arg);

unsigned int		ft_stsize(t_stack *st);

long				ft_atol(const char *str);

char				**ft_split(const char *str);

void				swap(char *str, t_stack *stack);
void				push(char *str, t_stack **dest, t_stack **src);
void				rotate(char *str, t_stack **stack);
void				reverse_rotate(char *str, t_stack **stack);
void				sort_for_three(t_stack **a);
void				sort_for_four(t_stack **a, t_stack **b);
void				ft_pretreatment(t_stack **a, t_stack **b);
void				radix_sort(t_stack **a, t_stack **b);
void				ft_error(void);
void				ft_free_for_str(char **lst);
void				ft_add_back(t_stack **stack, t_stack *stack_new);
void				ft_free_for_stack(t_stack *lst);
void				ft_putendl_fd(char *s, int fd);

#endif