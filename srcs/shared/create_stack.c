/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 03:23:01 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/15 03:23:05 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_stack(t_value *temp)
{
	t_value	*tempbis;

	if (!temp)
		return ;
	while (temp->previous)
		temp = temp->previous;
	while (temp->next)
	{
		tempbis = temp->next;
		free(temp);
		tempbis = temp->next;
	}
	free(temp);
}

static int		delete_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	return (0);
}

static int		split_table(t_value *start, char *str)
{
	char	**table;
	t_value	*temp;
	t_value *tempbis;
	int		i;

	table = ft_strsplit(str, ' ');
	temp = start;
	while (temp->next)
		temp = temp->next;
	i = 0;
	while (table[i])
	{
		if (!(temp->next = new_tvalue(table[i])))
		{
			free_stack(temp);
			return (delete_tab(table));
		}
		tempbis = temp;
		temp = temp->next;
		temp->previous = tempbis;
		i++;
	}
	delete_tab(table);
	return (1);
}

static int		first_argument(t_value **start, char *str)
{
	char	**table;
	t_value	*temp;
	t_value	*tempbis;
	int		i;

	temp = NULL;
	table = ft_strsplit(str, ' ');
	i = 1;
	if (!(*start = new_tvalue(table[0])))
		return (delete_tab(table));
	temp = *start;
	while (table[i])
	{
		if (!(temp->next = new_tvalue(table[i++])))
		{
			free_stack(temp);
			return (delete_tab(table));
		}
		tempbis = temp;
		temp = temp->next;
		temp->previous = tempbis;
	}
	delete_tab(table);
	return (1);
}

t_value			*create_stack(t_stack *stack_a, char **tab)
{
	t_value	*start;
	t_value	*temp;
	int		i;

	i = 2;
	if (!first_argument(&start, tab[1]))
		return (0);
	while (tab[i])
	{
		if (!split_table(start, tab[i]))
			return (0);
		i++;
	}
	temp = start;
	i = 1;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	temp->next = start;
	start->previous = temp;
	stack_a->len = i;
	stack_a->start = start;
	return (start);
}
