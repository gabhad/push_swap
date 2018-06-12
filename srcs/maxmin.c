/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:03:25 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/11 12:03:29 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_value(int i, int j, int k, int l)
{
	if (i <= j && i <= k && i <= l)
		return (i);
	else if (j <= i && j <= k && j <= l)
		return (j);
	else if (k <= i && k <= j && k <= l)
		return (k);
	else
		return (l);
}

int	is_second_max(t_value *number)
{
	t_value	*temp;
	int		j;

	j = 0;
	if (!number || !(number->next))
		return (0);
	temp = number->next;
	while (temp != number)
	{
		if (temp->value > number->value)
			j++;
		temp = temp->next;
	}
	if (j == 1)
		return (1);
	else
		return (0);
}

int	ismax(t_value *number)
{
	t_value	*temp;

	if (!number || !(number->next))
		return (0);
	temp = number->next;
	while (temp != number)
	{
		if (temp->value > number->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_second_min(t_value *number)
{
	t_value	*temp;
	int		j;

	j = 0;
	if (!number || !(number->next))
		return (0);
	temp = number->next;
	while (temp != number)
	{
		if (temp->value < number->value)
			j++;
		temp = temp->next;
	}
	if (j == 1)
		return (1);
	else
		return (0);
}

int	ismin(t_value *number)
{
	t_value	*temp;

	if (!number || !(number->next))
		return (0);
	temp = number->next;
	while (temp != number)
	{
		if (temp->value < number->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
