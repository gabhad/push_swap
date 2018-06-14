/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_b_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:15:11 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/12 16:15:37 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	i_is_min(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_value	*temp;
	int		j;

	j = 0;
	temp = stack_b->start;
	while (!is_second_max(temp))
	{
		temp = temp->next;
		j++;
	}
	while (!ismax(stack_b->start))
	{
		if (stack_b->start == temp)
			push_a(stack_a, stack_b);
		if (!ismax(stack_b->start))
			rotate_b(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
	if (j < i)
		swap_a(stack_a, stack_b);
}

void	rev_i_is_min(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_value	*temp;
	int		j;

	j = 0;
	temp = stack_b->start;
	while (!is_second_max(temp))
	{
		temp = temp->previous;
		j++;
	}
	while (!ismax(stack_b->start))
	{
		if (stack_b->start == temp)
			push_a(stack_a, stack_b);
		if (!ismax(stack_b->start))
			reverse_rotate_b(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
	if (j < i)
		swap_a(stack_a, stack_b);
}

void	j_is_min(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_value	*temp;
	int		j;

	j = 0;
	temp = stack_b->start;
	while (!is_second_min(temp))
	{
		temp = temp->next;
		j++;
	}
	while (!ismin(stack_b->start))
	{
		if (stack_b->start == temp)
			push_a(stack_a, stack_b);
		if (!ismin(stack_b->start))
			rotate_b(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
	rotate_a(stack_a, stack_b);
	if (j < i)
		rotate_a(stack_a, stack_b);
}

void	rev_j_is_min(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_value	*temp;
	t_value *tempbis;
	int		j;

	j = 0;
	temp = stack_b->start;
	tempbis = temp->next;
	if (!ismin(stack_b->start))
		while (!is_second_min(temp))
		{
			temp = temp->previous;
			j++;
		}
	while (!ismin(stack_b->start))
	{
		if (stack_b->start == temp)
			push_a(stack_a, stack_b);
		if (!ismin(stack_b->start))
			reverse_rotate_b(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
	rotate_a(stack_a, stack_b);
	if (j < i)
		rotate_a(stack_a, stack_b);
}
