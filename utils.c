/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:35 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 13:11:59 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	ft_word_count(const char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i])
			counter++;
		while (s[i] && !(s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *source, int len)
{
	int		k;
	char	*target;

	k = 0;
	target = malloc(sizeof(char) * (len + 1));
	if (!target)
		return (NULL);
	while (k < len)
	{
		target[k] = source[k];
		k++;
	}
	target[k] = '\0';
	return (target);
}

static char	**ft_split_cont(char **s, const char *str)
{
	int	i;
	int	start;
	int	k;

	k = 0;
	i = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
			i++;
		start = i;
		while (str[i] && !(str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
			i++;
		if (i > start)
		{
			s[k] = ft_strndup(&str[start], (i - start));
			if (!s[k])
				return (ft_free_for_str(s), NULL);
			k++;
		}
	}
	s[k] = NULL;
	return (s);
}

char	**ft_split(const char *str)
{
	char	**s;
	int		wc;

	wc = ft_word_count(str);
	s = malloc(sizeof(char *) * (wc + 1));
	if (!s)
		return (NULL);
	return (ft_split_cont(s, str));
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