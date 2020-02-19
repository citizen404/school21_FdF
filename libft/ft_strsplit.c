/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:09:52 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/27 16:46:38 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t k;

	if (!s || !*s)
		return (0);
	k = 0;
	while (*s)
	{
		s++;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			k++;
	}
	return (k);
}

static char		*get_word(char *i, char *j)
{
	char	*res;
	size_t	l;

	l = j - i + 1;
	if (!(res = (char *)malloc(l + 1)))
		return (NULL);
	while (i <= j)
		*(res++) = *(i++);
	*res = '\0';
	return (res - l);
}

static char		**make_free(char **words, size_t size)
{
	if (words && *words)
	{
		while (size)
		{
			ft_strdel(&words[size]);
			size--;
		}
		free(words);
		*words = NULL;
	}
	return ((char **)NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ar;
	char	*ps;
	char	*i;
	size_t	k;

	k = 0;
	if (!(ps = (char *)s) ||
			!(ar = (char**)malloc(sizeof(char *) * (count_words(ps, c) + 2))))
		return (NULL);
	i = ps;
	while (*ps)
	{
		if (*ps == c && *(ps + 1) != c)
			i = ps + 1;
		if (*ps != c && (*(ps + 1) == c || *(ps + 1) == '\0'))
		{
			if (!(*ar++ = get_word(i, ps)))
				return (make_free(ar, k));
			k++;
		}
		ps++;
	}
	*ar = NULL;
	return (ar - k);
}
