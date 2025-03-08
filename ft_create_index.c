/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:36:32 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/06 16:18:35 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_index(t_stack *a)
{
	int		k;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!a)
		ft_error();
	tmp1 = a;
	while (tmp1)
	{
		k = 0;
		tmp2 = a;
		while (tmp2)
		{
			if (tmp1->content > tmp2->content)
				k++;
			tmp2 = tmp2->next;
		}
		tmp1->index = k;
		tmp1 = tmp1->next;
	}
	return (a);
}
