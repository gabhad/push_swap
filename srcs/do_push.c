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

#include "../includes/push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (!stack_a->start)
		return ;
	temp = stack_a->start;
	temp->previous->next = temp->next;
	stack_b->start->previous->next = temp;
	temp->next = stack_b->start;
	stack_b->start = temp;
	stack_a->len = stack_a->len - 1;
	stack_b->len = stack_b->len + 1;
	ft_strjoinfree(stack_a->operations, ft_strdup("pb\n"));
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (!stack_b->start)
		return ;
	temp = stack_b->start;
	temp->previous->next = temp->next;
	stack_a->start->previous->next = temp;
	temp->next = stack_a->start;
	stack_a->start = temp;
	stack_a->len = stack_a->len + 1;
	stack_b->len = stack_b->len - 1;
	ft_strjoinfree(stack_a->operations, ft_strdup("pa\n"));
}
