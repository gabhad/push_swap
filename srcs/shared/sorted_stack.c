/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:44:47 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/08 13:44:53 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		a_is_sorted(t_stack *stack_a)
{
	t_value	*temp;

	if (stack_a->len == 0 || stack_a->len == 1)
		return (1);
	temp = stack_a->start;
	while (temp->next != stack_a->start)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		b_is_sorted(t_stack *stack_b)
{
	t_value	*temp;

	if (stack_b->len == 0 || stack_b->len == 1)
		return (1);
	if (stack_b->len == 2)
	{
		if (stack_b->start->value < stack_b->start->next->value)
			return (0);
		else
			return (1);
	}
	temp = stack_b->start->next;
	while (temp->next != stack_b->start)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
