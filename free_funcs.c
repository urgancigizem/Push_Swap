/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:17 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/04 17:08:47 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_for_str(char **lst)
{
	int	i;

	i = 0;
	if (!lst)
		return ;
	while (lst[i])
	{
		free(lst[i]);
		lst[i] = NULL;
		i++;
	}
	free(lst);
	lst = NULL;
}


#include <stdio.h>
void	ft_free_for_stack(t_stack **lst)
{
	t_stack *tmp;
	t_stack *current;

	current = *lst;
	tmp = NULL;
	if (!lst)
		return ;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
