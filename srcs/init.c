/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 23:28:00 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 18:08:06 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_init(int fd, t_map *map)
{
	t_mlxadr	mlx_adr;

	map->d.m = 0;			//начальные размеры карты
	map->d.n = 0;
	map->mlx_ptr = mlx_init();	//связь с рисовалкой
	if (fdf_create_img_win(map) == 0) //привязка окна и изображения в памяти
		fdf_exit(map);
	map->canvas = ft_read(fd, map); //читаем карту
	map->cnv_trm = ft_create_matrd(map->d.n, map->d.m); //создаем копию дабл
	map->buffer = (int*)mlx_get_data_addr(map->img_ptr, &mlx_adr.bits_per_pixel,
			&mlx_adr.size_line, &mlx_adr.endian); //спецфункция-буфер для хранения адресов
	map->z_h = 1;
	map->projection = ISO;
	map->cam.proj_per_k = -0.05;
	map->cam.position.x = (WIN_WIDTH) / 2;
	map->cam.position.y = (WIN_HEIGHT) / 2;
	map->shift.n = WIN_HEIGHT / 6;
	map->shift.m = (-1) * MENU_WIDTH / 2;
	map->angl.x = 0.0;
	map->angl.y = 0.0;
	map->angl.z = 0.0;
	return (1);
}
