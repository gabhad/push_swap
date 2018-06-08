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

void	rotate_s(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->start = stack_a->start->next;
	stack_b->start = stack_b->start->next;
	write(1, "rr\n", 3);
}

void	rotate_b(t_stack *stack_b);
{
	stack_b->start = stack_b->start->next;
	write(1, "rb\n", 3);
}

void	rotate_a(t_stack *stack_a);
{
	stack_a->start = stack_a->start->next;
	write(1, "ra\n", 3);
}