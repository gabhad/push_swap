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

#include "../includes/push_swap.c"

int	ismax(t_value *number)
{
	t_value	*temp;

	temp = number->next;
	while (temp != number)
	{
		if (temp->value > number->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ismin(t_value *number)
{
	t_value	*temp;

	temp = number->next;
	while (temp != number)
	{
		if (temp->value < number->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
