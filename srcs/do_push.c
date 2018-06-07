/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:58:56 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 11:59:12 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;
	t_value *tempbis;

	if (!(stack_a->start))
		return;
	temp = stack_a->start;
	tempbis = temp->next;
	temp->next = stack_b->start;
	stack_a->start = tempbis;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;
	t_value *tempbis;

	if (!(stack_b->start))
		return;
	temp = stack_b->start;
	tempbis = temp->next;
	temp->next = stack_a->start;
	stack_b->start = tempbis;
}