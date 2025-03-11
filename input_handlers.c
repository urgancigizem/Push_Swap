/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:32 by gurganci          #+#    #+#             */
/*   Updated: 2025/03/11 17:13:53 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_error(char **tmp)
{
	ft_free_for_str(tmp);
	ft_error();
}

static void	free_error_stack(t_stack *a)
{
	ft_free_for_stack(a);
	ft_error();
}

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
		free_error(tmp);
	i = 0;
	while (tmp[i])
	{
		if (valid_check(tmp[i]) == 0)
			free_error(tmp);
		number = ft_atol(tmp[i]);
		if (max_min_check(number) == 0)
			free_error(tmp);
		ft_add_back(&a, ft_new_stack(number));
		i++;
	}
	ft_free_for_str(tmp);
	return (a);
}

t_stack	*main_input_handlers(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;
	t_stack	*new;

	i = 0;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_split_string(argv[1]);
	while (++i < argc && argc > 2)
	{
		if (valid_check(argv[i]) == 0)
			ft_error();
		j = ft_atol(argv[i]);
		if (max_min_check(j) == 0)
			ft_error();
		new = ft_new_stack(j);
		if (!new)
			free_error_stack(a);
		ft_add_back(&a, new);
	}
	return (a);
}
