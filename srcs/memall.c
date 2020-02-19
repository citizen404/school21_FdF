/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <lconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:44:46 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/19 18:08:06 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				**ft_create_matr(int n, int m)
{
	int				i;
	t_point			**matr;

	i = -1;
	if ((matr = (t_point**)malloc(sizeof(t_point*) * n)) == NULL)
		return (NULL);
	else
		while (++i < n)
		{
			if ((matr[i] = (t_point*)malloc(sizeof(t_point) * m)) == NULL)
				while (--i >= 0)
					free(matr[i]);
		}
	return (matr);
}

t_dpoint			**ft_create_matrd(int n, int m)
{
	int				i;
	t_dpoint		**matr;

	i = -1;
	if ((matr = (t_dpoint**)malloc(sizeof(t_dpoint*) * n)) == NULL)
		return (NULL);
	else
		while (++i < n)
		{
			if ((matr[i] = (t_dpoint*)malloc(sizeof(t_dpoint) * m)) == NULL)
				while (--i >= 0)
					free(matr[i]);
		}
	return (matr);
}

int				fdf_create_img_win(t_map *map)
{
	if ((map->win_ptr =
			mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")) == NULL)
		return (print_error(5));
	if ((map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (print_error(5));
	return (1);
}
