/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:59:25 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 11:59:49 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, stack_b);
	rotate_b(stack_a, stack_b);
}

void	rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->len < 2)
		return ;
	stack_b->start = stack_b->start->next;
	stack_a->operations = add_text(stack_a->operations, "rb\n");
}

void	rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len < 2)
		return ;
	stack_a->start = stack_a->start->next;
	stack_a->operations = add_text(stack_a->operations, "ra\n");
}
