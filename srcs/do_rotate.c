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
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rotate_b(t_stack *stack_b);
{
	t_value	*temp;
	t_value *tempbis;

	if (!stack_b || !(stack_b->next))
		return;
	temp = stack_b->start;
	tempbis = temp->next;
	while (stack_b->next)
		temp = temp->next;
	temp->next = stack_b->start;
	stack_b->start = tempbis;
}

void	rotate_a(t_stack *stack_a);
{
	t_value	*temp;
	t_value *tempbis;

	if (!stack_a || !(stack_a->next))
		return;
	temp = stack_a->start;
	tempbis = temp->next;
	while (stack_a->next)
		temp = temp->next;
	temp->next = stack_a->start;
	stack_a->start = tempbis;
}