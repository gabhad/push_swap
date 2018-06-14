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

static int	check_operations(char *line)
{
	if (!ft_strcmp(line, "pa")
		&& !ft_strcmp(line, "pb")
		&& !ft_strcmp(line, "sa")
		&& !ft_strcmp(line, "sb")
		&& !ft_strcmp(line, "ss")
		&& !ft_strcmp(line, "ra")
		&& !ft_strcmp(line, "rb")
		&& !ft_strcmp(line, "rr")
		&& !ft_strcmp(line, "rra")
		&& !ft_strcmp(line, "rrb")
		&& !ft_strcmp(line, "rrr"))
		return (0);
	else
		return (1);
}

void		read_output(t_stack *stack_a)
{
	char	*line;
	t_stack	*stack_b;

	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	while (get_next_line(0, &line))
	{
		if (!check_operations(line))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else
			do_operations(stack_a, stack_b, line);
	}
	if (a_is_sorted(stack_a) && !stack_b->start)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_b);
	return (0);
}