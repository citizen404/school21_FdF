/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:58:25 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/20 18:50:56 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_error(int i)
{
	if (i == 0)
		ft_putstr("Usage: ./fdf map_file\n");
	if (i == 1)
		ft_putstr("Invalid map_file\n");
	if (i == 2)
		ft_putstr("Reading error\n");
	if (i == 3)
		ft_putstr("Map initialization failure\n");
	if (i == 4)
		ft_putstr("Camera initialization failure\n");
	if (i == 5)
		ft_putstr("Fdf initialization failure\n");
	return (0);
}

void	print_error_exit(int i, t_map *map)
{
	if (i == 6)
		ft_putstr("Map file failure. Exiting.\n");
	fdf_exit(map);
}
