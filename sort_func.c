/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:28:42 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 17:11:49 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_three(t_stack **a)
{
	t_stack	*curr;
	int		first;
	int		second;
	int		third;

	curr = *a;
	first = curr->index;
	second = curr->next->index;
	third = curr->next->next->index;
	if ((first > second) && (second < third) && (first < third))
		swap("sa", *a);
	else if ((first < second) && (second > third) && (first < third))
	{
		swap("sa", *a);
		rotate("ra", a);
	}
	else if ((first > second) && (second > third) && (first > third))
	{
		swap("sa", *a);
		reverse_rotate("rra", a);
	}
	else if ((first > second) && (second < third) && (first > third))
		rotate("ra", a);
	else if ((first < second) && (second > third) && (first > third))
		reverse_rotate("rra", a);
}

void	sort_for_four(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = ft_stsize(*a);
	while (a_size > 3 && *a != NULL)
	{
		if (*a && ((*a)->index == 0))
			push("pb", b, a);
		else if (*a)
			rotate("ra", a);
		a_size = ft_stsize(*a);
	}
	if (*a && ft_stsize(*a) == 3)
		sort_for_three(a);
	push("pa", a, b);
}

void	ft_pretreatment(t_stack **a, t_stack **b)
{
	int	a_size;
	int	i;

	i = 0;
	a_size = ft_stsize(*a);
	while (a_size > 3 && a != NULL && i < 5)
	{
		if ((*a)->index == 0)
			push("pb", b, a);
		else if ((*a)->index == 1)
			push("pb", b, a);
		else
			rotate("ra", a);
		a_size = ft_stsize(*a);
		i++;
	}
	if (a && ft_stsize(*a) == 3)
		sort_for_three(a);
	while (ft_stsize(*b) > 0)
		push("pa", a, b);
	if ((*a)->index > (*a)->next->index)
		swap("sa", *a);
}

static int	ft_bit_calculate(t_stack **a)
{
	int	bit_size;
	int	a_size;

	bit_size = 0;
	a_size = ft_stsize(*a);
	while (a_size > 1 && ++bit_size)
		a_size /= 2;
	return (bit_size);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	bit_size;
	int	a_size;

	bit_size = ft_bit_calculate(a);
	ft_pretreatment(a, b);
	a_size = ft_stsize(*a);
	bit_size = ft_bit_calculate(a);
	i = -1;
	while (++i <= bit_size && !ft_check_for_sort(*a))
	{
		a_size = ft_stsize(*a);
		while (a_size-- && !ft_check_for_sort(*a))
		{
			if ((((*a)->index >> i) & 1) == 0)
				push("pb", b, a);
			else
				rotate("ra", a);
		}
		while (*b)
			push("pa", a, b);
	}
}
