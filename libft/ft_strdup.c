/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:48:10 by lconchit          #+#    #+#             */
/*   Updated: 2019/09/28 01:20:01 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *src)
{
    int        i;
    char    *s;
    
    i = 0;
    while (src[i])
    {
        i++;
    }
    s = NULL;
    s = (char *)malloc(sizeof(char) * i + 1);
    if (s == NULL)
        return (NULL);
    i = 0;
    while (src[i] != '\0')
    {
        s[i] = src[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}
