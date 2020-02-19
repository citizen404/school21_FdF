/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:07:08 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/22 17:42:35 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t l;
	size_t k;

	if (n >= ft_strlen(s2))
		return (ft_strcat(s1, s2));
	else
	{
		l = ft_strlen(s1);
		s1 = s1 + l;
		k = n;
		while (k != 0)
		{
			*s1++ = *s2++;
			k--;
		}
		*s1 = '\0';
		return (s1 - l - n);
	}
}
