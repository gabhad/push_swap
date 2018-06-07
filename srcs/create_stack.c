/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:58:29 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/05 08:58:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	*create_stack(char **tab)
{
	t_value	*start;
	t_value	*temp;
	int		i;

	i = 1;
	start->value = ft_lstnew(ft_atoi(argv[0]), sizeof(t_value));
	temp = start;
	while (tab[i])
	{
		temp->next = ft_lstnew(ft_argv[i], sizeof(t_value));
		temp = temp->next;
		i++;
	}
	return (start);
}