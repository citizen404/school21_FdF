/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:45:34 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/27 16:13:34 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (size + 1 < size)
		return (NULL);
	res = (char *)(malloc(size + 1));
	if (res != NULL)
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	return (NULL);
}
