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

# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/ft_printf.h"
# include "string.h"
# define BUFF_SIZE 32

typedef struct	s_value
{
	int					value;
	struct s_value		*next;
	struct s_value		*previous;
}				t_value;

typedef struct	s_stack
{
	t_value				*start;
	int					len;
	char				*operations;
}				t_stack;

t_value			*create_stack(char **tab);
intmax_t		push_swap_atoi(const char *str);
void			swap_a(t_stack *stack_a, t_stack *stack_b);
void			swap_b(t_stack *stack_a, t_stack *stack_b);
void			swap_s(t_stack *stack_a, t_stack *stack_b);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			push_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_a(t_stack *stack_a, t_stack *stack_b);
void			rotate_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_r(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_r(t_stack *stack_a, t_stack *stack_b);
int				a_is_sorted(t_stack *stack_a);

int				b_is_sorted(t_stack *stack_b);
int				calc_median(t_stack *stack);
void			swap_solver(t_stack *stack_a);
void			algo(t_stack *stack_a, t_stack *stack_b);
void			arrange_b(t_stack *stack_a, t_stack *stack_b);
int				ismax(t_value *number);
int				is_second_max(t_value *number);
int				ismin(t_value *number);
int				is_second_min(t_value *number);
int				min_value(int i, int j, int k, int l);
void			simplify_operations(t_stack *stack);
char			*add_text(char *s1, char *s2);
void			i_is_min(t_stack *stack_a, t_stack *stack_b, int i);
void			rev_i_is_min(t_stack *stack_a, t_stack *stack_b, int i);
void			j_is_min(t_stack *stack_a, t_stack *stack_b, int i);
void			rev_j_is_min(t_stack *stack_a, t_stack *stack_b, int i);

int				get_next_line(const int fd, char **line);
void			do_operations(t_stack *stack_a, t_stack *stack_b, char *operation);
void			read_output(t_stack *stack_a);


#endif
