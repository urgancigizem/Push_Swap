/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:19 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 13:11:25 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, t_stack *stack)
{
	int	content;
	int	index;

	if (!stack || !(stack->next))
		return ;
	content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content;
	index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = index;
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
	*stack = (*stack)->next;
	last = ft_last(*stack);
	last->next = top;
	top->next = NULL;
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
