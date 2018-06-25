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
#include "unistd.h"

static int		is_double(t_stack *stack_a)
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

static int		delete_stack(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*bis;

	if (!stack_a->len)
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

int				main(int argc, char **argv)
{
	t_value	*start;
	t_stack *stack_a;

	if (argc == 1)
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
	read_output(stack_a);
	if (stack_a->operations)
		ft_strdel(&stack_a->operations);
	return (delete_stack(stack_a));
}
