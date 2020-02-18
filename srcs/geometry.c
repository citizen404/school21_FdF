/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:41:37 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/13 04:18:40 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotation(t_map *map)
{
	rot_x(map, map->angl.x, map->cnv_trm);
	rot_y(map, map->angl.y, map->cnv_trm);
	rot_z(map, map->angl.z, map->cnv_trm);
}

void			rot_z(t_map *map, double alpha, t_dpoint **array)
{
	int			i;
	int			j;
	t_dpoint	tmp;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			tmp = array[i][j];
			map->cnv_trm[i][j].x = tmp.x * cos(alpha) + tmp.y * sin(alpha);
			map->cnv_trm[i][j].y = -tmp.x * sin(alpha) + tmp.y * cos(alpha);
			map->cnv_trm[i][j].z = map->z_h * tmp.z;
		}
		j = -1;
	}
}

void			rot_y(t_map *map, double alpha, t_dpoint **array)
{
	int			i;
	int			j;
	int			k;
	t_dpoint	tmp;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			tmp = array[i][j];
			k = map->z_h * tmp.z;
			map->cnv_trm[i][j].x = tmp.x * cos(alpha) - k * sin(alpha);
			map->cnv_trm[i][j].y = tmp.y;
			map->cnv_trm[i][j].z = tmp.x * sin(alpha) + k * cos(alpha);
		}
		j = -1;
	}
}

void			rot_x(t_map *map, double alpha, t_dpoint **array)
{
	int			i;
	int			j;
	int			k;
	t_dpoint	tmp;

	i = -1;
	j = -1;
	while (++i < map->d.n)
	{
		while (++j < map->d.m)
		{
			tmp = array[i][j];
			k = map->z_h * tmp.z;
			map->cnv_trm[i][j].x = tmp.x;
			map->cnv_trm[i][j].y = tmp.y * cos(alpha) + k * sin(alpha);
			map->cnv_trm[i][j].z = -tmp.y * sin(alpha) + k * cos(alpha);
		}
		j = -1;
	}
}

int			dist(t_dpoint p1, t_dpoint p2)
{
	int		l;

	l = sqrt(p2.sx * p2.sx - 2 * p2.sx * p1.sx + p1.sx * p1.sx +
			p2.sy * p2.sy - 2 * p2.sy * p1.sy + p1.sy * p1.sy);
	return (l);
}
