/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:43:33 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/24 01:26:00 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char *ps;

	ps = (char *)s;
	while (ps && *ps)
		ft_putchar_fd(*(ps++), fd);
	ft_putchar_fd('\n', fd);
}
