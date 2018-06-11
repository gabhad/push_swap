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

#include "../includes/push_swap.h"

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (stack_a->start && stack_a->start->next != stack_a->start)
	{
		temp = stack_a->start->next;
		stack_a->start->next = temp->next;
		temp->next = stack_a->start;
		stack_a->start = temp;
	}
	if (stack_b->start && stack_b->start->next != stack_b->start)
	{
		temp = stack_b->start->next;
		stack_b->start->next = temp->next;
		temp->next = stack_b->start;
		stack_b->start = temp;
	}
	stack_a->operations = ft_strjoinfree(stack_a->operations, ft_strdup("ss\n"));
}

void	swap_b(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (!stack_b->start || stack_b->start->next == stack_b->start)
		return ;
	temp = stack_b->start->next;
	stack_b->start->next = temp->next;
	temp->next = stack_b->start;
	stack_b->start = temp;
	stack_a->operations = ft_strjoinfree(stack_a->operations, ft_strdup("sb\n"));
}

void	swap_a(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	(void)stack_b;
	if (!stack_a->start || stack_a->start->next == stack_a->start)
		return ;
	temp = stack_a->start->next;
	stack_a->start->next = temp->next;
	temp->next = stack_a->start;
	stack_a->start = temp;
	stack_a->operations = ft_strjoinfree(stack_a->operations, ft_strdup("sa\n"));
}
