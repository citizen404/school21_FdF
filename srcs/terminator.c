/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:49:24 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/12 22:20:11 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			destroy_split(char **st)
{
	int			i;

	i = -1;
	while (st[++i] != '\0')
		free(((void*)st[i]));
	free((void*)st);
}

void			del_list(void *s, size_t size)
{
	free(s);
	size = 0;
}

void			destroy_map(t_map *map)
{
	int			i;

	i = -1;
//	while (++i < map->d.n)
//		free(map->canvas[i]);
	free((void*)map->canvas);
	i = -1;
//	while (++i < map->d.n)
//		free(map->cnv_trm[i]);
	free((void*)map->cnv_trm);
}

void			fdf_exit(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	destroy_map(map);
	exit(0);
}
