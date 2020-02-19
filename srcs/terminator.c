/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:49:24 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 19:32:31 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			destroy_split(char **st)
{
	int			i;

	i = -1;
	if (!st)
		return ;
	while (*st && st[++i] != '\0')
		free(((void*)st[i]));
	free((void*)st);
}

void			del_list(void *s, size_t size)
{
	if (!s)
		return;
	free(s);
	size = 0;
}

void			destroy_map(t_map *map)
{
	int			i;

	i = -1;
	free((void*)map->canvas);
	i = -1;
	free((void*)map->cnv_trm);
}

void			fdf_exit(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	destroy_map(map);
	exit(0);
}
