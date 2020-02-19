/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:46:46 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 17:36:55 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_background(t_map *map, int color)
{
	int		i;
	int		lenght;

	i = -1;
	lenght = WIN_WIDTH * WIN_HEIGHT;
	while (++i < lenght)
		map->buffer[i] = color;
}

void		draw_menu(t_map *map)
{
	int		y;
	int		c;
	void	*mlx;
	void	*win;

	y = (WIN_HEIGHT / 2);
	c = 0x00FF7F;
	mlx = map->mlx_ptr;
	win = map->win_ptr;
	mlx_string_put(mlx, win, WIN_WIDTH - 70, y = 10, c, "Press:");
	mlx_string_put(mlx, win, WIN_WIDTH - 110, y += 25, c, "-/+ - zoom");
	mlx_string_put(mlx, win, WIN_WIDTH - 120, y += 25, c, "<,> - move");
	mlx_string_put(mlx, win, WIN_WIDTH - 260,
			y += 25, c, "W/S,A/D,Q/E - rotate");
	mlx_string_put(mlx, win, WIN_WIDTH - 210, y += 25, c, "I,P - projection");
	mlx_string_put(mlx, win, WIN_WIDTH - 100, y += 25, c, "R - reset");
	mlx_string_put(mlx, win, WIN_WIDTH - 110, y += 25, c, "Esc - exit");
}

void		draw_map(t_map map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < map.d.n)
	{
		while (++j < map.d.m)
		{
			if (j < map.d.m - 1)
				draw_line(map.canvas[i][j], map.canvas[i][j + 1], &map);
			if (i < map.d.n - 1)
				draw_line(map.canvas[i][j], map.canvas[i + 1][j], &map);
		}
		j = -1;
	}
}

void		draw(t_map *map)
{
	int		i;

	transform(map);
	rotation(map);
	if (map->projection == UP_VIEW)
		up_mod(map);
	else if (map->projection == ISO)
		iso_mod(map);
	else if (map->projection == PERSP)
		persp_mod(map);
	draw_background(map, COLOR_BACKGR);
	draw_map(*map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	i = mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	draw_menu(map);
}
