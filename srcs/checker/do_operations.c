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

void	do_operations(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (ft_strcmp(operation, "pa"))
		push_a(stack_a, stack_b);
	if (ft_strcmp(operation, "pb"))
		push_b(stack_a, stack_b);
	if (ft_strcmp(operation, "sa"))
		swap_a(stack_a, stack_b);
	if (ft_strcmp(operation, "sb"))
		swap_b(stack_a, stack_b);
	if (ft_strcmp(operation, "ss"))
		swap_s(stack_a, stack_b);
	if (ft_strcmp(operation, "ra"))
		rotate_a(stack_a, stack_b);
	if (ft_strcmp(operation, "rb"))
		rotate_b(stack_a, stack_b);
	if (ft_strcmp(operation, "rr"))
		rotate_r(stack_a, stack_b);
	if (ft_strcmp(operation, "rra"))
		reverse_rotate_a(stack_a, stack_b);
	if (ft_strcmp(operation, "rrb"))
		reverse_rotate_b(stack_a, stack_b);
	if (ft_strcmp(operation, "rrr"))
		reverse_rotate_r(stack_a, stack_b);
}
