/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:08:16 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/26 19:33:58 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*ps;
	unsigned int	i;

	ps = s;
	if (!ps || !f)
		return ;
	i = 0;
	while (ps && *ps)
	{
		f(i, ps++);
		i++;
	}
}
