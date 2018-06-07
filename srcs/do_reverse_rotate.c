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
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_value	*temp;
	t_value	*tempbis;

	if (!stack_b || !(stack_b->next))
		return;
	temp = stack_b->start;
	while (temp->next->next)
	{
		temp = temp->next;
		tempbis = temp->next;
	}
	tempbis->next = stack_b->start;
	temp->next = NULL;
	stack_b->start = tempbis;
}

void	reverse_rotate_a(t_stack *stack_a)
{
	t_value	*temp;
	t_value	*tempbis;

	if (!stack_a || !(stack_a->next))
		return;
	temp = stack_a->start;
	while (temp->next->next)
	{
		temp = temp->next;
		tempbis = temp->next;
	}
	tempbis->next = stack_a->start;
	temp->next = NULL;
	stack_a->start = tempbis;
}