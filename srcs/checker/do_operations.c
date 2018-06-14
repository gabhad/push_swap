/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:54:52 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/14 08:55:01 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (!ft_strcmp(op, "pa"))
		push_a(stack_a, stack_b);
	if (!ft_strcmp(op, "pb"))
		push_b(stack_a, stack_b);
	if (!ft_strcmp(op, "sa"))
		swap_a(stack_a, stack_b);
	if (!ft_strcmp(op, "sb"))
		swap_b(stack_a, stack_b);
	if (!ft_strcmp(op, "ss"))
		swap_s(stack_a, stack_b);
	if (!ft_strcmp(op, "ra"))
		rotate_a(stack_a, stack_b);
	if (!ft_strcmp(op, "rb"))
		rotate_b(stack_a, stack_b);
	if (!ft_strcmp(op, "rr"))
		rotate_r(stack_a, stack_b);
	if (!ft_strcmp(op, "rra"))
		reverse_rotate_a(stack_a, stack_b);
	if (!ft_strcmp(op, "rrb"))
		reverse_rotate_b(stack_a, stack_b);
	if (!ft_strcmp(op, "rrr"))
		reverse_rotate_r(stack_a, stack_b);
}
