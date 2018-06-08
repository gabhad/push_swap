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
	write(1, "rrr\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	stack_b->start = stack_b->start->previous;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	stack_a->start = stack_a->start->previous;
	write(1, "rra\n", 4);
}