/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:22 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 13:10:47 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}
