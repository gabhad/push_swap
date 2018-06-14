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

static void		delete_stack(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*bis;

	if (!stack_a->start)
		return ;
	temp = stack_a->start;
	if (!temp->next)
	{
		free(temp);
		return ;
	}
	while (temp->next)
	{
		bis = temp->next;
		temp->next = NULL;
		temp->previous = NULL;
		free(temp);
		temp = bis;
	}
	temp->previous = NULL;
	temp->next = NULL;
	free(temp);
}

static t_stack	*fill_stack(t_stack *stack_a, int argc, char **argv)
{
	t_value		*start;

	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	start = create_stack(argv);
	stack_a->start = start;
	stack_a->len = argc - 1;
	stack_a->operations = NULL;
	return (stack_a);
}

static int		check_error_bis(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 2;
	while (i < argc - 2)
	{
		if (push_swap_atoi(argv[i]) > 2147483647 ||
			push_swap_atoi(argv[i]) < -2147483648)
			return (0);
		while ((i + j) < argc - 1)
		{
			if (!ft_strcmp(argv[i], argv[i + j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

static int		check_errors(int argc, char **argv)
{
	int			i;

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
	if (!check_error_bis(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_stack		*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (1);
	if (check_errors(argc, argv))
		return (1);
	if (!(stack_a = fill_stack(stack_a, argc, argv)))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	read_output(stack_a);
	delete_stack(stack_a);
	if (stack_a->operations)
		ft_strdel(&stack_a->operations);
	free(stack_a);
	return (0);
}
