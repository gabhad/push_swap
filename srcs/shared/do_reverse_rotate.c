/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:59:54 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 12:00:06 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->start = stack_a->start->previous;
	stack_b->start = stack_b->start->previous;
	stack_a->operations = add_text(stack_a->operations, "rrr\n");
}

void	reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->len < 2)
		return ;
	stack_b->start = stack_b->start->previous;
	stack_a->operations = add_text(stack_a->operations, "rrb\n");
}

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len < 2)
		return ;
	stack_a->start = stack_a->start->previous;
	stack_a->operations = add_text(stack_a->operations, "rra\n");
}
