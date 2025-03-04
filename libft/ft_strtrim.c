/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:44:00 by gurganci          #+#    #+#             */
/*   Updated: 2024/10/26 09:58:30 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s;
	char	*str;

	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len_s = ft_strlen(s1);
	while (len_s && s1[len_s - 1] && ft_strchr(set, s1[len_s - 1]) != 0)
		len_s--;
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len_s);
	str[len_s] = '\0';
	return (str);
}
