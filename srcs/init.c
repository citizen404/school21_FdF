/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 23:28:00 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/12 23:23:44 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "fdf.h"

t_fdf		*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		terminate_fdf(fdf, 5);
	if (!(fdf->mlx = mlx_init()))
		terminate_fdf(fdf, 5);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		terminate_fdf(fdf, 5);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
										&(fdf->size_line), &(fdf->endian));*/
//	fdf->map = map;
	//if (!(fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
	//	terminate(ERR_FDF_INIT);
//	return (fdf);
/*}

t_camera	*init_cam(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		terminate_fdf(fdf, 4);
	camera->scale = (int)(WIN_WIDTH/ fdf->map->width / 2);
	camera->ar_x = 0;
	camera->ar_y = 0;
	camera->ar_z = 0;
	camera->pos_x = WIN_WIDTH / 2;
	camera->pos_y = WIN_HEIGHT / 2;
	camera->scale_z = 1;
	return (camera);
}

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		print_error(3);
	map->width = 0;
	map->height = 0;
	map->points = NULL;
	return (map);
}

void		*reset_fdf(t_fdf *fdf)
{
	fdf->camera->scale = 20;
	fdf->camera->scale_z = 1;
	fdf->camera->projection_type = 0;
	fdf->camera->dwx = 0;
	fdf->camera->dwy = 0;
	fdf->camera->ar_x = 0.0;
	fdf->camera->ar_y = 0.0;
	fdf->camera->ar_z = 0.0;
	return (0);
}*/

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
