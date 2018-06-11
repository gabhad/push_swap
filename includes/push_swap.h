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
#include "../libftprintf/includes/ft_printf.h"

typedef struct 		s_value
{
	int					value;
	struct s_value		*next;
	struct s_value		*previous;
}					t_value;

typedef struct		s_stack
{
	t_value				*start;
	int					len;
	char				*operations;
}					t_stack;

t_value		*create_stack(char **tab);
void		swap_a(t_stack *stack_a, t_stack *stack_b);
void		swap_b(t_stack *stack_a, t_stack *stack_b);
void		swap_s(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack_a, t_stack *stack_b);
void		rotate_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_s(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);
int			a_is_sorted(t_stack *stack_a);
int			b_is_sorted(t_stack *stack_b);
int			calc_median(t_stack *stack);
void		swap_solver(t_stack *stack_a);
void		algo(t_stack *stack_a, t_stack *stack_b);
int			ismax(t_value *number);
int			ismin(t_value *number);
void		simplify_operations(t_stack *stack);

#endif
