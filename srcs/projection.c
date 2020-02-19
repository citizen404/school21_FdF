/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <lconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:57:08 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 18:08:06 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		persp_mod(t_map *map)
{
	int		i;
	int		j;
	double	k;
	double	zc;

	i = -1;
	j = -1;
	k = 16;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			zc = map->cnv_trm[i][j].z * map->cam.proj_per_k + k;
			if (zc > 0)
			{
				map->canvas[i][j].sx = map->shift.m +
						round(map->cnv_trm[i][j].x * k / zc) +
						WIN_WIDTH / 2;
				map->canvas[i][j].sy = map->shift.n +
						round(map->cnv_trm[i][j].y * k / zc) + WIN_HEIGHT / 2;
			}
		}
		j = -1;
	}
}

void		iso_mod(t_map *map)
{
	int		i;
	int		j;
	int		sx;
	int		sy;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			sx = map->shift.m + round(map->cnv_trm[i][j].x)
					+ WIN_WIDTH / 2;
			sy = map->shift.n + round((map->cnv_trm[i][j].y -
					map->cnv_trm[i][j].z)) + WIN_HEIGHT / 2;
			map->canvas[i][j].sx = sx;
			map->canvas[i][j].sy = sy;
		}
		j = -1;
	}
}

void		up_mod(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			map->canvas[i][j].sx = map->shift.m +
					round(map->cnv_trm[i][j].x) + WIN_WIDTH / 2;
			map->canvas[i][j].sy = map->shift.n +
					round(map->cnv_trm[i][j].y) + WIN_HEIGHT / 2;
		}
		j = -1;
	}
}