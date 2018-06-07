/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:58:29 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 11:59:19 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	swap_b(t_stack *stack_b)
{
	t_value	*temp;
	t_value *tempbis;

	if (!(stack_b->start) || !(stack_b->next))
		return;
	temp = stack_b->start->next;
	tempbis = temp->next;
	temp->next = stack_b->start;
	start->next = tempbis;
	stack_b->start->next = tempbis;
	stack_b->start = temp;
}

void	swap_a(t_stack *stack_a)
{
	t_value	*temp;
	t_value *tempbis;

	if (!(stack_a->start) || !(stack_a->next))
		return;
	temp = stack_a->start->next;
	tempbis = temp->next;
	temp->next = stack_a->start;
	start->next = tempbis;
	stack_a->start->next = tempbis;
	stack_a->start = temp;
}
