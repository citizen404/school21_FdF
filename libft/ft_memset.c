/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:12:41 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/22 17:36:26 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *ustr;
	unsigned char uc;

	ustr = (unsigned char *)str;
	uc = (unsigned char)c;
	while (ustr < (unsigned char *)str + n)
		*(ustr++) = uc;
	return (str);
}
