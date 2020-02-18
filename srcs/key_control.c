/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:11:26 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/13 04:19:22 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == ZOOM_IN)
		fdf->camera->scale += 1;
	if (key == ZOOM_OUT)
		fdf->camera->scale -= 1;
	if (fdf->camera->scale < 1)
		fdf->camera->scale = 1;
}

void	move(int key, t_fdf *fdf)
{
if (key == MOVE_LEFT)
	fdf->camera->dwx += 5;
if (key == MOVE_RIGHT)
	fdf->camera->dwx -= 5;
if (key == MOVE_UP)
	fdf->camera->dwy += 5;
if (key == MOVE_DOWN)
	fdf->camera->dwy -= 5;
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == ROT_X_CW)
		fdf->camera->ar_x += RAD;
	if (key == ROT_X_RCW)
		fdf->camera->ar_x -= RAD;
	if (key == ROT_Y_CW)
		fdf->camera->ar_y += RAD;
	if (key == ROT_Y_RCW)
		fdf->camera->ar_y -=RAD;
	if (key == ROT_Z_CW)
		fdf->camera->ar_z += RAD;
	if (key == ROT_Z_RCW)
		fdf->camera->ar_z -= RAD;
}

int     key_hook(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == ESC)
		terminate_fdf(fdf, 0);
	if (key == ISO || key == PRSP1)
		fdf->camera->projection_type = 1;
		//projection(key, map);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, fdf);
	if (key == ROT_X_CW || key == ROT_X_RCW || key == ROT_Y_CW ||
	  key == ROT_Y_RCW || key == ROT_Z_CW || key == ROT_Z_RCW)
		rotate(key, fdf);
	if (key == MOVE_UP || key == MOVE_DOWN || key == MOVE_LEFT
			|| key == MOVE_RIGHT)
		move(key, fdf);
	if (key == RESET)
		reset_fdf(fdf);
	if (key == 0)
		fdf->camera->scale_z += 1;
	if (key == 6)
		fdf->camera->scale_z -= 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf->map, fdf);
	return (0);
}*/

#include "fdf.h"

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
	if (key == RESET)
		reset(map);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, map);
	if (key == RX_D || key == RX_UP || key == RY_D || key == RY_UP ||
						key == RZ_D || key == RZ_UP)
		rotate(key, map);
	if (key == MOVE_DOWN || key == MOVE_UP)
		map->shift.n = (key == MOVE_DOWN) ? map->shift.n - 10 : map->shift.n + 10;
	if (key == MOVE_LEFT || key == MOVE_RIGHT)
		map->shift.m = (key == MOVE_LEFT) ? map->shift.m - 10 : map->shift.m + 10;
	if (key == ESC)
		fdf_exit(map);
	if (key == UP_VIEW || key == ISO || key == PERSP)
		fdf_change_projection(key, map);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (1);
}
