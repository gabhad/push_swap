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

#include "../includes/push_swap.h"

static t_value	*new_tvalue(int value)
{
	t_value	*new;

	if (!(new = (t_value*)malloc(sizeof(t_value))))
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_value			*create_stack(char **tab)
{
	t_value	*start;
	t_value	*temp;
	t_value *tempbis;
	int		i;

	i = 2;
	start = new_tvalue(ft_atoi(tab[1]));
	temp = start;
	while (tab[i])
	{
		temp->next = new_tvalue(ft_atoi(tab[i]));
		tempbis = temp;
		temp = temp->next;
		temp->previous = tempbis;
		i++;
	}
	temp->next = start;
	start->previous = temp;
	return (start);
}
