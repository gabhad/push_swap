/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:34:47 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/12 15:34:49 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	compare_outcomes(t_stack *stack_a, t_stack *stack_b, int i, int j)
{
	int len_b;

	len_b = stack_b->len;
	if (i == min_value(i, j, len_b - i, len_b - j))
		i_is_min(stack_a, stack_b, i);
	else if (j == min_value(i, j, len_b - i, len_b - j))
		j_is_min(stack_a, stack_b, j);
	else if (len_b - i == min_value(i, j, len_b - i, len_b - j))
		rev_i_is_min(stack_a, stack_b, len_b - i);
	else
		rev_j_is_min(stack_a, stack_b, len_b - j);
	if (stack_a->start->value > stack_a->start->next->value)
		swap_a(stack_a, stack_b);
}

static void	shortest_path(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	t_value	*temp;

	temp = stack_b->start;
	i = 0;
	j = 0;
	while (!ismax(temp))
	{
		i++;
		temp = temp->next;
	}
	temp = stack_b->start;
	while (!ismin(temp))
	{
		j++;
		temp = temp->next;
	}
	compare_outcomes(stack_a, stack_b, i, j);
}

void		arrange_b(t_stack *stack_a, t_stack *stack_b)
{
	if (b_is_sorted(stack_b))
	{
		while (stack_b->len)
			push_a(stack_a, stack_b);
	}
	else
		while (stack_b->len > 0)
		{
			while (ismax(stack_b->start))
				push_a(stack_a, stack_b);
			if (!stack_b->len)
				return ;
			shortest_path(stack_a, stack_b);
		}
}
