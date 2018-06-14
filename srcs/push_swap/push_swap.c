/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:22:50 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 08:23:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	check_error_bis(char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (push_swap_atoi(argv[i]) > 2147483647 ||
			push_swap_atoi(argv[i]) < -2147483648)
			return (0);
		while (argv[i + j])
		{
			if (!ft_strcmp(argv[i], argv[i + j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	check_errors(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && ft_strcmp(argv[i], "0") != 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (!check_error_bis(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_value	*start;
	t_stack *stack_a;
	int		len;

	if (argc == 1)
		return (0);
	if (check_errors(argv))
		return (0);
	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	start = create_stack(argv);
	stack_a->start = start;
	stack_a->len = argc - 1;
	stack_a->operations = NULL;
	swap_solver(stack_a);
	len = ft_strlen(stack_a->operations);
	write(1, stack_a->operations, len);
	ft_strdel(&stack_a->operations);
	free(stack_a);
	return (0);
}
