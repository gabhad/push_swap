/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:41:29 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/04 16:42:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.h"

typedef struct s_value
{
	int		value;
	t_value	next;
}				t_value;

typedef struct s_stack
{
	t_value	*start;
	t_value	*next;
}				t_stack;

t_value		*create_stack(char **tab);
void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
void		swap_s(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack_a);
void		rotate_b(t_stack *stack_b);
void		rotate_s(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_a(t_stack *stack_a);
void		reverse_rotate_b(t_stack *stack_b);
void		reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);

#endif
