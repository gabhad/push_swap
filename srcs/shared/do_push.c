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

static void	clean_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	temp = stack_a->start->previous;
	temp->next = stack_b->start;
	stack_b->start->next = stack_a->start;
	stack_b->start->previous = stack_a->start->previous;
	stack_a->start = stack_b->start;
	stack_b->start = NULL;
	stack_b->len = 0;
	stack_a->len += 1;
	stack_a->operations = add_text(stack_a->operations, "pa\n");
}

static void	initialize_b(t_stack *stack_a, t_stack *stack_b, t_value *temp)
{
	stack_b->start = temp;
	stack_b->start->previous = stack_b->start;
	stack_b->start->next = stack_b->start;
	stack_a->len = stack_a->len - 1;
	stack_b->len = stack_b->len + 1;
	stack_a->operations = add_text(stack_a->operations, "pb\n");
}

void		push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (!stack_a->len)
		return ;
	temp = stack_a->start;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	stack_a->start = temp->next;
	if (!(stack_b->start))
	{
		initialize_b(stack_a, stack_b, temp);
		return ;
	}
	temp->next = stack_b->start;
	temp->previous = stack_b->start->previous;
	stack_b->start->previous->next = temp;
	stack_b->start = temp;
	temp = temp->next;
	temp->previous = stack_b->start;
	stack_a->len = stack_a->len - 1;
	stack_b->len = stack_b->len + 1;
	stack_a->operations = add_text(stack_a->operations, "pb\n");
}

void		push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_value	*temp;

	if (!(stack_b->start))
		return ;
	if (stack_b->len == 1)
	{
		clean_stack_b(stack_a, stack_b);
		return ;
	}
	temp = stack_b->start;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	stack_b->start = temp->next;
	temp->next = stack_a->start;
	temp->previous = stack_a->start->previous;
	temp->previous->next = temp;
	stack_a->start = temp;
	temp = temp->next;
	temp->previous = stack_a->start;
	stack_a->len = stack_a->len + 1;
	stack_b->len = stack_b->len - 1;
	stack_a->operations = add_text(stack_a->operations, "pa\n");
}
