/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:26 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 16:09:10 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = main_input_handlers(argc, argv);
	if (ft_check_for_dup(a) || !a)
	{
		ft_free_for_stack(a);
		ft_error();
	}
	a = ft_create_index(a);
	if (ft_check_for_sort(a) == 0)
	{
		if (ft_stsize(a) == 2 && a->index > a->next->index)
			swap("sa", a);
		else if (ft_stsize(a) == 3)
			sort_for_three(&a);
		else if (ft_stsize(a) == 4)
			sort_for_four(&a, &b);
		else
			radix_sort(&a, &b);
	}
	ft_free_for_stack(a);
	return (0);
}
