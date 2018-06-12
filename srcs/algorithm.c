/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:47:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/12 13:47:54 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	arrange_b(t_stack *stack_a, t_stack *stack_b)
{

}

static void	algo_suite(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		len;

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
			if (stack_a->start->value < median)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a, stack_b);
		}
	}
	arrange_b(stack_a, stack_b)
}

void		algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	int		median_b;
	int		len;

	median_a = calc_median(stack_a);
	median_b = calc_median(stack_b);
	len = stack_a->len;
	while (stack_b_len < len / 2)
	{
		if (stack_a->start->value < median_a)
		{
			push_b(stack_a, stack_b);
			if (stack_b->start->value < median_b)
				rotate_b(stack_a, stack_b);
		}
		else
			rotate_a(stack_a, stack_b);
	}
	algo_suite(stack_a, stack_b);
}