/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:23:35 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/13 03:31:32 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d ", map->points[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/

int		main(int ac, char **av)
{
	int	fd;
	t_map	map;

	if (ac != 2)
		return(print_error(0));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return(print_error(1));
	if (fdf_init(fd, &map) == 0)		//инициализация
	{
		return(print_error(3));
		exit(0);
	}
	close(fd);
	draw(&map);				//первичная отрисовка карты
	mlx_key_hook(map.win_ptr, key_hook, (void *)&map); //контроль клавиш и отрисовка
	mlx_loop(map.mlx_ptr);
	return (0);
}
