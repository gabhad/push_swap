/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:23:01 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/16 03:23:05 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	testval(char *str)
{
	if (push_swap_atoi(str) > 2147483647 || push_swap_atoi(str) < -2147483648)
		return (0);
	return (1);
}

t_value		*new_tvalue(char *str)
{
	t_value	*new;
	int		i;

	i = 1;
	if (!str)
		return (NULL);
	if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (NULL);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	if (!testval(str))
		return (NULL);
	if (!(new = (t_value*)malloc(sizeof(t_value))))
		return (NULL);
	new->value = ft_atoi(str);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
