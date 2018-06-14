/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:11:10 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/14 08:11:20 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(t_stack *stack_a, int argc, char **argv)
{
	t_value *start;

	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	start = create_stack(argv);
	stack_a->start = start;
	stack_a->len = argc - 1;
	stack_a->operations = NULL;
}

static int	check_error_bis(char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (argv[i])
	{
		if (push_swap_atoi(argv[i]) > 2147483647 || 
			push_swap_atoi(argv[i]) < -2147483648)
			{
				write(1, "Error\n", 6);
				return (0);
			}
		while (argv[i + j])
		{
			if (!ft_strcmp(argv[i], argv[i + j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
		j = i + 1;
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
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (1);
	if (check_errors(argv))
		return (1);
	fill_stack(stack_a, argc, argv);
	read_output(stack_a);
	free(stack_a);
	return (0);
}