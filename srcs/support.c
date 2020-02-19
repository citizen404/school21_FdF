/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:49:43 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 18:08:06 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int   max_ab(int a, int b)
{
	return ((a - b) > 0 ? a : b);
}

int   ft_abs(int a)
{
	return ((a < 0) ? a * (-1) : a);
}

char	*ft_skiptab(char *str)
{
	while (str[0] == '\n' || str[0] == '\t' || str[0] == '\v' ||
				str[0] == '\f' || str[0] == '\r' || str[0] == ' ')
		str++;
	return (str);
}

int	word_count(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			len++;
		while (*s != c && *s)
			s++;
	}
	return (len);
}

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		while (tmp && (tmp->next) != NULL)
			tmp = tmp->next;
		new->next = NULL;
		tmp->next = new;
	}
}
