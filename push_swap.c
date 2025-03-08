/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:26 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 13:11:35 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;

	a = NULL;
	b = NULL;
	a = main_input_handlers(argc, argv);
	if (ft_check_for_dup(a) || !a)
	{
		ft_free_for_stack(a);
		ft_error();
	}
	a_size = ft_stsize(a);
	a = ft_create_index(a);
	if (ft_check_for_sort(a) == 0)
	{
		if (a_size == 2 && a->index > a->next->index)
			swap("sa", a);
		else if (a_size == 3)
			sort_for_three(&a);
		else if (a_size == 4)
			sort_for_four(&a, &b);
		else if (a_size == 5)
			sort_for_five(&a, &b);
		else
			radix_sort(&a, &b);
	}
	if (a)
		ft_free_for_stack(a);
	if (b)
	{
		ft_free_for_stack(b);
	}
	return (0);
}
