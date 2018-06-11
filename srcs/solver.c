/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:09:33 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/11 09:09:35 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	algo(stack_a, stack_b);
	free(stack_b);
}