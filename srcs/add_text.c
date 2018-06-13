/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 08:27:04 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/12 08:27:05 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*add_text(char *s1, char *s2)
{
	char	*final;

	final = ft_strjoinfree(s1, ft_strdup(s2));
	return (final);
}
