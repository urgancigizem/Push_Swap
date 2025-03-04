/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:22 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/04 14:46:12 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int content, t_stack *a)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	// new = a;
	if (!new)
	{
		ft_free_for_stack(&a);
		ft_free_for_stack(&new);
		ft_error();
	}	
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}
