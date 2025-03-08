/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:17 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 13:09:49 by gurganci         ###   ########.fr       */
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

void	ft_free_for_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	if (stack == NULL)
		return ;
	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
