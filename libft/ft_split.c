/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:48:27 by gurganci          #+#    #+#             */
/*   Updated: 2024/10/29 17:17:53 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static int	ft_word_counter(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	const char	*start;
	int			word_counts;
	int			i;

	i = -1;
	word_counts = ft_word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_counts + 1));
	if (!str)
		return (NULL);
	while (++i < word_counts)
	{
		while (*s == c)
			s++;
		start = s;
		s = ft_strchr(s, c);
		str[i] = ft_substr(start, 0, s - start);
		if (str[i] == NULL)
		{
			ft_free(str, i);
			return (NULL);
		}
	}
	str[i] = NULL;
	return (str);
}
