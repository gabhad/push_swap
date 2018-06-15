/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:36:23 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/11 11:36:26 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	arrange_b_under_10(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_value	*temp;

	i = 0;
	while (stack_b->len > 0)
	{
		while (ismax(stack_b->start))
			push_a(stack_a, stack_b);
		if (!stack_b->len)
			return ;
		temp = stack_b->start;
		while (!ismax(temp))
		{
			i++;
			temp = temp->next;
		}
		while (!ismax(stack_b->start))
		{
			if (i > stack_b->len / 2)
				reverse_rotate_b(stack_a, stack_b);
			else
				rotate_b(stack_a, stack_b);
		}
	}
}

static void	algo_suite(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_value	*temp;

	i = 0;
	while (!(a_is_sorted(stack_a)))
	{
		while (ismin(stack_a->start))
			push_b(stack_a, stack_b);
		temp = stack_a->start;
		while (!ismin(temp))
		{
			i++;
			temp = temp->next;
		}
		while (!ismin(stack_a->start))
		{
			if (i > stack_a->len / 2)
				reverse_rotate_a(stack_a, stack_b);
			else
				rotate_a(stack_a, stack_b);
		}
	}
	arrange_b_under_10(stack_a, stack_b);
}

void		algo_under_10(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		len;

	median = calc_median(stack_a);
	len = stack_a->len;
	while (stack_b->len < len / 2)
	{
		if (stack_a->start->value < median)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
	}
	while (!(ismin(stack_a->start)) && !(ismax(stack_b->start)))
	{
		if (!(ismin(stack_a->start)))
			rotate_a(stack_a, stack_b);
		if (!(ismax(stack_b->start)))
			rotate_b(stack_a, stack_b);
	}
	if (a_is_sorted(stack_a) == 1)
		arrange_b(stack_a, stack_b);
	else
		algo_suite(stack_a, stack_b);
}
