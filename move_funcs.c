/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:19 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/04 15:07:11 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second;

	if (size <= 1)
		return ;
	first = *stack;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stack **dest, t_stack **src)
{
	t_stack	*top;

	if (!src || !*src)
		return ;
	top = *src;
	*src = (*src)->next;
	top->next = *dest;
	*dest = top;
	ft_putendl_fd(str, 1);
}

void	rotate(char *str, t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;

	if (!stack || !*stack)
		return ;
	top = *stack;
	last = ft_lstlast(*stack);
	*stack = top->next;
	top->next = NULL;
	last->next = top;
	ft_putendl_fd(str, 1);
}

void	reverse_rotate(char *str, t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_putendl_fd(str, 1);
}
