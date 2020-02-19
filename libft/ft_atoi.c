/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 23:29:54 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/26 20:23:53 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	skip_gaps(char *st)
{
	size_t i;

	i = 0;
	while (st[i] == ' ' || st[i] == '\t' || st[i] == '\n' ||
			st[i] == '\v' || st[i] == '\f' || st[i] == '\r')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	long int	n;
	size_t		i;
	size_t		d;

	n = 0;
	d = 0;
	i = skip_gaps((char *)str);
	if (str[i] == '-')
		d++;
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((n = (10 * n) + (str[i] - '0')) < 0)
		{
			if (d == 0)
				return (-1);
			return (0);
		}
		i++;
	}
	if (d > 0)
		return (n * (-1));
	return (n);
}
