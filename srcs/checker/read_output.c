/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:31:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/14 08:32:09 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_stack_b(t_stack *stack_b)
{
	t_value	*temp;
	t_value	*bis;

	if (!stack_b->start)
	{
		free(stack_b);
		return ;
	}
	temp = stack_b->start;
	if (!temp->next)
	{
		free(temp);
		free(stack_b);
		return ;
	}
	while (temp->next)
	{
		bis = temp->next;
		free(temp);
		temp = bis;
	}
	free(temp);
	free(stack_b);
}

static int	check_operations(char *line)
{
	if (!ft_strcmp(line, "pa") ||
		!ft_strcmp(line, "pb") ||
		!ft_strcmp(line, "sa") ||
		!ft_strcmp(line, "sb") ||
		!ft_strcmp(line, "ss") ||
		!ft_strcmp(line, "ra") ||
		!ft_strcmp(line, "rb") ||
		!ft_strcmp(line, "rr") ||
		!ft_strcmp(line, "rra") ||
		!ft_strcmp(line, "rrb") ||
		!ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

void		read_output(t_stack *stack_a)
{
	char	*line;
	t_stack	*stack_b;

	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	stack_b->start = NULL;
	stack_b->len = 0;
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_operations(line))
		{
			write(1, "Error\n", 6);
			del_stack_b(stack_b);
			return ;
		}
		do_op(stack_a, stack_b, line);
		ft_strdel(&line);
	}
	if (a_is_sorted(stack_a) && !stack_b->start)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	del_stack_b(stack_b);
}
