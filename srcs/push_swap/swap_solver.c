/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:09:33 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/11 09:09:35 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_solver(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (a_is_sorted(stack_a))
		return ;
	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	stack_b->len = 0;
	stack_b->start = NULL;
	algo(stack_a, stack_b);
	free(stack_b);
	simplify_operations(stack_a);
}