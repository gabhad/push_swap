/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:33:50 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/21 10:33:53 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_suite(t_stack *stack_a, t_stack *stack_b)
{
	if (ismin(stack_a->start->next))
	{
		rotate_a(stack_a, stack_b);
		return ;
	}
	swap_a(stack_a, stack_b);
	reverse_rotate_a(stack_a, stack_b);
}

void		sort_3(t_stack *stack_a, t_stack *stack_b)
{
	if (a_is_sorted(stack_a))
		return ;
	if (ismin(stack_a->start))
	{
		rotate_a(stack_a, stack_b);
		swap_a(stack_a, stack_b);
		reverse_rotate_a(stack_a, stack_b);
		return ;
	}
	if (is_second_min(stack_a->start))
	{
		if (ismin(stack_a->start->next))
		{
			swap_a(stack_a, stack_b);
			return ;
		}
		reverse_rotate_a(stack_a, stack_b);
		return ;
	}
	sort_suite(stack_a, stack_b);
}
