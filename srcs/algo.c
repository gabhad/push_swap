/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:47:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/12 13:47:54 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	algo_suite(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		length;

	if (a_is_sorted(stack_a))
	{
		arrange_b(stack_a, stack_b);
		return ;
	}
	while (!a_is_sorted(stack_a))
	{
		median = calc_median(stack_a);
		length = stack_a->len;
		while (stack_a->len > length / 2)
		{
			write(1, "tutu\n", 5); // infinite loop ici
			if (stack_a->start->value < median)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a, stack_b);
		}
	}
	arrange_b(stack_a, stack_b);
}

void		algo(t_stack *stack_a, t_stack *stack_b)
{
	int		median_a;
	int		median_b;
	int		len;

	median_a = calc_median(stack_a);
	len = stack_a->len;
	while (stack_b->len < len / 2)
	{
		if (stack_a->start->value < median_a)
		{
			push_b(stack_a, stack_b);
			median_b = calc_median(stack_b);
			if (stack_b->start->value < median_b)
				rotate_b(stack_a, stack_b);
		}
		else
			rotate_a(stack_a, stack_b);
	}
	algo_suite(stack_a, stack_b);
}