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

static int		delete_tab(char **tab, t_value *temp)
{
	int		i;
	t_value *tempbis;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	if (temp)
	{
		while (temp->previous)
		{
			printf("tutu");
			temp = temp->previous;
		}
		while (temp->next)
		{
			printf("toto");
			tempbis = temp->next;
			printf("tintin");
			free(temp);
			printf("tata");
			temp = tempbis;
		}
		free(temp);
	}
	return (0);
}

static t_value	*new_tvalue(char *str)
{
	t_value	*new;
	int		i;

	i = 1;
	if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (NULL);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	if (!(new = (t_value*)malloc(sizeof(t_value))))
		return (NULL);
	new->value = ft_atoi(str);
	new->next = NULL;
	new->previous = NULL;
	return (new);
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
		if (!(temp->next = new_tvalue(table[i++])))
			return (delete_tab(table, temp));
		tempbis = temp;
		temp = temp->next;
		temp->previous = tempbis;
	}
	i = delete_tab(table, temp);
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
		return (delete_tab(table, temp));
	temp = *start;
	while (table[i])
	{
		if (!(temp->next = new_tvalue(table[i++])))
			return (delete_tab(table, temp));
		tempbis = temp;
		temp = temp->next;
		temp->previous = tempbis;
	}
	i = delete_tab(table, temp);
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
