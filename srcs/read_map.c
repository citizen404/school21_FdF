/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 23:44:40 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/20 19:30:49 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_dpoint	*ft_get_point(t_dpoint **canvas, int i, char **st, t_map *map)
{
	int			j;
	char		**s;

	canvas[i] = (t_dpoint*)malloc(map->d.m * sizeof(t_dpoint));
	j = 0;
	while (j < map->d.m)
	{
		s = ft_strsplit(st[j], ',');
		canvas[i][j].x = (j - map->d.m / 2);
		canvas[i][j].y = (i - map->d.n / 2);
		canvas[i][j].z = ft_atoi(s[0]);
		canvas[i][j].color = (s[1] == NULL) ? COLOR_LINE : COLOR_BACKGR;
		j++;
		destroy_split(s);
	}
	return (canvas[i]);
}

int				fdf_def_sizel(t_map *map)
{
	if (map->d.m > map->d.n)
		return (WIN_WIDTH * G_R / map->d.m);
	else
		return (WIN_HEIGHT * G_R / map->d.n);
}

t_dpoint		**ft_str_to_point(t_list *l, t_map *map)
{
	int			i;
	char		**st;
	t_dpoint	**canvas;
	char		*s;

	canvas = (t_dpoint**)malloc(map->d.n * sizeof(t_dpoint));
	s = (char*)l->content;
	if (map->d.m == 0)
		map->d.m = word_count(s, ' ');
	map->scale = fdf_def_sizel(map);
	i = 0;
	while (i < map->d.n)
	{
		st = ft_strsplit((char*)l->content, ' ');
		if (map->d.m != 0 && map->d.m !=
				((int)word_count((char*)l->content, ' ')))
			print_error_exit(6, map);
		canvas[i] = ft_get_point(&canvas[i], i, st, map);
		destroy_split(st);
		i++;
		l = l->next;
	}
	return (canvas);
}

static void		def_value(char **line, t_list **lrow)
{
	*lrow = NULL;
	*line = "";
}

t_dpoint		**ft_read(int fd, t_map *map)
{
	char		*line;
	t_dpoint	**canvas;
	char		*ch;
	t_list		*lrow;

	def_value(&line, &lrow);
	while (fd != 0 && line != NULL)
	{
		if ((map->projection = get_next_line(fd, &line)) == 0)
		{
			free(line);
			break ;
		}
		if (line == NULL)
			break ;
		ch = ft_strsub(line, 0, ft_strlen(line));
		map->d.n++;
		ft_lstaddback(&lrow, ft_lstnew(ch, sizeof(char*) * ft_strlen(ch)));
		free((void*)ch);
		free((void*)line);
	}
	canvas = ft_str_to_point(lrow, map);
	ft_lstdel(&lrow, &del_list);
	return (canvas);
}
