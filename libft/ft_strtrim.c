/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:20:44 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/24 01:24:26 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (s[i] != '\0' &&
			(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (i < j &&
			(s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t'))
		j--;
	if (i == j)
		return (ft_strnew(1));
	return (ft_strsub(s, i, j - i));
}
