/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:17:07 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/23 17:37:27 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ps;
	char *res;
	char *pres;

	if (s == NULL)
		return (NULL);
	res = ft_memalloc((size_t)ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	ps = (char *)s;
	pres = res;
	while (*ps)
		if (f(*ps))
			*(pres++) = f(*(ps++));
	return (res);
}
