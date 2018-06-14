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
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
}

void	swap_b(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!stack_b->start || stack_b->len == 1)
		return ;
	temp = stack_b->start->value;
	stack_b->start->value = stack_b->start->next->value;
	stack_b->start->next->value = temp;
	stack_a->operations = add_text(stack_a->operations, "sb\n");
}

void	swap_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	(void)stack_b;
	if (!stack_a->start || stack_a->len == 1)
		return ;
	temp = stack_a->start->value;
	stack_a->start->value = stack_a->start->next->value;
	stack_a->start->next->value = temp;
	stack_a->operations = add_text(stack_a->operations, "sa\n");
}
