/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <lconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:56:37 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/20 18:15:23 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zoom_z(int key, t_map *map)
{
	if (key == Z_UP)
		map->z_h += 0.1;
	if (key == Z_DOWN)
		map->z_h -= 0.1;
	transform(map);
}

void			fdf_offset(t_dpoint **canvas, t_size s_canvas, t_point k)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i < s_canvas.n)
	{
		while (++j < s_canvas.m)
		{
			canvas[i][j].x = canvas[i][j].x + k.x;
			canvas[i][j].y = canvas[i][j].y + k.y;
		}
		j = -1;
	}
}

void			transform(t_map *map)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			map->cnv_trm[i][j].x = map->canvas[i][j].x * map->scale;
			map->cnv_trm[i][j].y = map->canvas[i][j].y * map->scale;
			map->cnv_trm[i][j].z = map->canvas[i][j].z * map->z_h *
					map->scale;
		}
		j = -1;
	}
}
