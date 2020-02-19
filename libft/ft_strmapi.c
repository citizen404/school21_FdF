/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:14:52 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/24 01:44:07 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ps;
	char			*res;
	char			*pres;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	res = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	ps = (char *)s;
	pres = res;
	i = 0;
	while (ps[i] != '\0')
	{
		*(pres++) = f(i, ps[i]);
		i++;
	}
	return (res);
}
