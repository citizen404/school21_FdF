/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:49:34 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/24 22:08:49 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int nb)
{
	size_t k;

	k = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		k++;
	}
	while (nb > 9)
	{
		nb /= 10;
		k++;
	}
	return (k + 1);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		k;

	i = get_len(n);
	k = i;
	res = ft_strnew(k);
	if (!res)
		return (NULL);
	if (n > -1)
		n = n * (-1);
	else
		res[0] = '-';
	while (n < -9)
	{
		i--;
		res[i] = -(n % 10) + '0';
		n = n / 10;
	}
	res[i - 1] = -(n % 10) + '0';
	if (k > 0)
		res[k + 1] = '\0';
	return (res);
}
