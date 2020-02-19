/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:11:26 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 17:44:41 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void			reset(t_map *map)
{
	map->angl.x = 0;
	map->angl.y = 0;
	map->angl.z = 0;
	map->shift.m = 0;
	map->shift.n = 0;
	map->z_h = 1;
	map->projection = UP_VIEW;
	map->scale = fdf_def_sizel(map);
}

void			zoom(int key, t_map *map)
{
	if (key == ZOOM_OUT && map->scale > 1)
		map->scale--;
	if (key == ZOOM_IN)
		if (map->scale < 40)
			map->scale++;
}

void			fdf_change_projection(int key, t_map *map)
{
	if (key == UP_VIEW)
		map->projection = UP_VIEW;
	if (key == ISO)
	{
		map->angl.x = -0.523599;
		map->angl.y = 0;
		map->angl.z = 0.785398;
		map->projection = ISO;
	}
	if (key == PERSP)
		map->projection = PERSP;
	draw(map);
}

void			rotate(int key, t_map *map)
{
	if (key == RX_D)
		map->angl.x -= RAD;
	if (key == RX_UP)
		map->angl.x += RAD;
	if (key == RY_D)
		map->angl.y -= RAD;
	if (key == RY_UP)
		map->angl.y += RAD;
	if (key == RZ_D)
		map->angl.z -= RAD;
	if (key == RZ_UP)
		map->angl.z += RAD;
}

int				key_hook(int key, void *param)
{
	t_map		*map;

	map = (t_map*)param;
	printf("%d\n", key);
	if (key == RESET)
		reset(map);
	if (key == Z_UP)
	{
		map->z_h += 0.1;
		transform(map);
	}
	if (key == Z_DOWN)
	{
		map->z_h -= 0.1;
		transform(map);
	}
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, map);
	if (key == RX_D || key == RX_UP || key == RY_D || key == RY_UP ||
						key == RZ_D || key == RZ_UP)
		rotate(key, map);
	if (key == MOVE_DOWN || key == MOVE_UP)
		map->shift.n = (key == MOVE_DOWN) ?
			map->shift.n - 10 : map->shift.n + 10;
	if (key == MOVE_LEFT || key == MOVE_RIGHT)
		map->shift.m = (key == MOVE_LEFT) ?
			map->shift.m - 10 : map->shift.m + 10;
	if (key == ESC)
		fdf_exit(map);
	if (key == UP_VIEW || key == ISO || key == PERSP)
		fdf_change_projection(key, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (1);
}
