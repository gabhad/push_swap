/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:40:51 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/08 14:40:55 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*sort_list(int *list, int len)
{
	int		i;
	int		temp;

	i = 0;
	while (i < len - 1)
	{
		if (list[i] > list[i + 1])
		{
			temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (list);
}

static int	*fill_list(t_stack *stack, int *list, int len)
{
	int		i;
	t_value	*temp;

	temp = stack->start;
	i = 0;
	while (i < len)
	{
		list[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (list);
}

static int	get_stack_len(t_stack *stack)
{
	int		i;
	t_value	*temp;

	i = 1;
	if (!stack->start)
		return (0);
	temp = stack->start;
	while (temp->next != stack->start)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

static int	get_median(t_stack *stack)
{
	int		*list;
	int		len;
	int		median;

	len = get_stack_len(stack);
	if (!(list = (int*)malloc(sizeof(int) * len)))
		return (-1);
	list = fill_list(stack, list, len);
	list = sort_list(list, len);
	if (len % 2 == 1)
	{
		len = len / 2;
		median = list[len];
	}
	else
	{
		len = len / 2;
		median = (list[len] + list[len + 1]) / 2;
	}
	free(list);
	return (median);
}

int			calc_median(t_stack *stack)
{
	int		median;

	if (stack->start->next == stack->start)
		return (stack->start->value);
	else if (stack->start->next->next == stack->start)
		return ((stack->start->value + stack->start->next->value) / 2);
	median = get_median(stack);
	return (median);
}
