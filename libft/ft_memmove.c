/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:52:10 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/22 17:39:31 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	if (src == dst)
		return (dst);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (p2 < p1)
		while (++i <= len)
			p1[len - i] = p2[len - i];
	else
		while (len-- > 0)
			*p1++ = *p2++;
	return (dst);
}
