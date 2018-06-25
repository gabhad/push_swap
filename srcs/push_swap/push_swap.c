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
#include <unistd.h>

static int	is_double(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*tempbis;

	temp = stack_a->start;
	while (temp->next != stack_a->start)
	{
		tempbis = temp->next;
		while (tempbis != stack_a->start)
		{
			if (tempbis->value == temp->value)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			tempbis = tempbis->next;
		}
		temp = temp->next;
	}
	return (0);
}

static int	delete_stack(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*bis;

	if (!stack_a->start)
	{
		free(stack_a);
		return (0);
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
	free(stack_a);
	return (0);
}

static int	check_error_bis(int argc, char **argv)
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

static int	check_errors(int argc, char **argv)
{
	int		i;

	if (check_error_bis(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], " "))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
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
	if (check_errors(argc, argv))
		return (0);
	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	if (!(start = create_stack(stack_a, argv)))
	{
		free(stack_a);
		write(1, "Error\n", 6);
		return (0);
	}
	if (is_double(stack_a))
		return (delete_stack(stack_a));
	stack_a->start = start;
	stack_a->operations = NULL;
	swap_solver(stack_a);
	len = ft_strlen(stack_a->operations);
	write(1, stack_a->operations, len);
	ft_strdel(&stack_a->operations);
	return (delete_stack(stack_a));
}
