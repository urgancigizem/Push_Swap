/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:31:20 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 16:33:35 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		write(fd, "NULL", 4);
	else
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

unsigned int	ft_stsize(t_stack *lst)
{
	int	node;

	node = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		node++;
	}
	return (node);
}

t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
