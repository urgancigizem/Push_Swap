/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:43:51 by gurganci          #+#    #+#             */
/*   Updated: 2024/10/26 14:37:56 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberofdigit(int n)
{
	int	digit;
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	if (sign == 1)
		digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	digit = ft_numberofdigit(n);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	digit--;
	while (n > 0)
	{
		str[digit] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (str);
}
