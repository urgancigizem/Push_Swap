/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:35 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 16:46:43 by gurganci         ###   ########.fr       */
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

static char	*ft_strndup(const char *str, int len)
{
	int		k;
	char	*copy;

	k = 0;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (k < len)
	{
		copy[k] = str[k];
		k++;
	}
	copy[k] = '\0';
	return (copy);
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
