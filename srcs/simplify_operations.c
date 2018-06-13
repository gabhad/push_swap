/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:16:37 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/11 14:16:48 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*change_text(char *str, char *dest, char *src)
{
	char	*new_reply;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(str) + ft_strlen(dest) - ft_strlen(src);
	new_reply = ft_strnew(len);
	len = ft_strlen(str) - ft_strlen(ft_strstr(str, src));
	while (++i < len)
		new_reply[i] = str[i];
	len = 0;
	while (dest[len])
		new_reply[i++] = dest[len++];
	len = i - ft_strlen(dest) + ft_strlen(src);
	while (str[len])
		new_reply[i++] = str[len++];
	ft_strdel(&str);
	return (new_reply);
}

void		simplify_operations(t_stack *stack)
{
	while (strstr(stack->operations, "ra\nrb"))
		stack->operations = change_text(stack->operations, "rr", "ra\nrb");
	while (strstr(stack->operations, "sa\nsb"))
		stack->operations = change_text(stack->operations, "ss", "sa\nsb");
	while (strstr(stack->operations, "rra\nrrb"))
		stack->operations = change_text(stack->operations, "rrr", "rra\nrrb");
	while (strstr(stack->operations, "pb\npa"))
		stack->operations = change_text(stack->operations, "", "pb\npa\n");
	while (strstr(stack->operations, "pa\npb"))
		stack->operations = change_text(stack->operations, "", "pa\npb\n");
}
