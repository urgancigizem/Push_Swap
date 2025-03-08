/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:32 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/08 11:41:59 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_split_string(char *argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		number;

	a = NULL;
	i = 0;
	tmp = ft_split(argv);
	while (tmp[i] != NULL)
		i++;
	if (i == 0 || argv == NULL)
	{
		ft_free_for_str(tmp);
		ft_error();
	}
	i = 0;
	while (tmp[i])
	{
		if (valid_check(tmp[i]) == 0)
		{
			ft_free_for_str(tmp);
			ft_error();
		}
		number = ft_atol(tmp[i]);
		if (max_min_check(number) == 0)
		{
			ft_free_for_str(tmp);
			ft_error();
		}
		ft_add_back(&a, ft_new_stack(number));
		i++;
	}
	ft_free_for_str(tmp);
	return (a);
}

int	max_min_check(long long int number)
{
	if (number > INTMAX || number < INTMIN)
		return (0);
	return (1);
}

int	valid_check(const char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!(arg[i] >= 48 && arg[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*main_input_handlers(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;
	t_stack	*new;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_split_string(argv[1]);
	else
	{
		while (i < argc)
		{
			if (valid_check(argv[i]) == 0)
				ft_error();
			j = ft_atol(argv[i]);
			if (max_min_check(j) == 0)
				ft_error();
			new = ft_new_stack(j);
			if (!new)
			{
				ft_free_for_stack(a);
				ft_error();
			}
			ft_add_back(&a, new);
			i++;
		}
	}
	return (a);
}
