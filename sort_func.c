/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:28:42 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/04 15:06:35 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_three(t_stack *a, int max)
{
	int	size;

	size = ft_lstsize(a);
	if (a->next->next->index != max)
	{
		if (a->index == max)
			rotate("ra", &a);
		else
			reverse_rotate("rra", &a);
	}
	if (a->index > a->next->index)
		swap("sa", &a, size);
}
void	sort_for_four(t_stack *a, t_stack *b)
{
	int	b_size;

	b_size = ft_lstsize(b);
	while (b_size < 1 && a != NULL)
	{
		if (a && (a->index == 0))
			push("pb", &b, &a);
		else if(a)
			rotate("ra", &a);
		if(b)
			b_size = ft_lstsize(b);
	}
	if(a && ft_lstsize(a) == 3)
		sort_for_three(a, 3);
	while (b)
		push("pa", &a, &b);
}

void	sort_for_five(t_stack *a, t_stack *b)
{
	int	b_size;
	int a_size;

	b_size = ft_lstsize(b);
	a_size = ft_lstsize(a);
	while (a_size > 3 && a != NULL)
	{
		if (a && (a->index == 0))
			push("pb", &b, &a);
		else if (a && (a->index == 1))
			push("pb", &b, &a);
		else if(a)
			rotate("ra", &a);
		a_size = ft_lstsize(a);	
	}
	b_size = ft_lstsize(b);
	if (b && b->index == 0)
		swap("sb", &b, b_size);
	if(a && ft_lstsize(a) == 3)
		sort_for_three(a, 4);
	while (b)
		push("pa", &a, &b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int i;
	int bit_size;
	int a_size;

	bit_size = 0;
	a_size = ft_lstsize(a);
	while (a_size > 1 && ++bit_size)
		a_size /= 2;
	++bit_size;
	i = -1;
	while (++i <= bit_size)
	{
		a_size = ft_lstsize(a);
		while (a_size-- && !ft_check_for_sort(a))
		{
			if (((a->index >> i) & 1) == 0)
				push("pb", &b, &a);
			else
				rotate("ra", &a);
		}
		while (b)
		push("pa", &a, &b);
	}
}
