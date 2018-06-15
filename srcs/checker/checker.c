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
	{
		free(stack_a);
		return ;
	}
	temp = stack_a->start;
	temp->previous->next = NULL;
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
			return (1);
		while ((i + j) < argc - 1)
		{
			if (!ft_strcmp(argv[i], argv[i + j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

static int		check_errors(int argc, char **argv)
{
	if (check_error_bis(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_value	*start;
	t_stack *stack_a;

	if (argc == 1)
		return (0);
	if (check_errors(argc, argv))
		return (0);
	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	if (!(start = create_stack(stack_a, argv)))
	{
		stack_a->start = start;
		delete_stack(stack_a);
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a->start = start;
	stack_a->operations = NULL;
	read_output(stack_a);
	delete_stack(stack_a);
	if (stack_a->operations)
		ft_strdel(&stack_a->operations);
	free(stack_a);
	return (0);
}
