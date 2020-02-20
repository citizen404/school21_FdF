/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:23:35 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/20 18:01:12 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		fd;
	t_map	map;
	char	c;

	if (ac != 2)
		return (print_error(0));
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, &c, 0) < 0)
		return (print_error(1));
	if (fdf_init(fd, &map) == 0)
	{
		return (print_error(3));
		exit(0);
	}
	close(fd);
	draw(&map);
	mlx_key_hook(map.win_ptr, key_hook, (void *)&map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
