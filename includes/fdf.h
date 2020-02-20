/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:25:32 by lconchit          #+#    #+#             */
/*   Updated: 2020/02/20 18:45:19 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define MENU_WIDTH 220

# define G_R 0.58
# define COLOR_LINE 0xfffafa
# define COLOR_BACKGR 0x000000

# define UP_VIEW 32
# define ISO 34
# define RESET 15
# define PERSP   35

# define RX_UP 1
# define RX_D 13
# define RY_UP 0
# define RY_D 2
# define RZ_UP 12
# define RZ_D 14
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define Z_UP 6
# define Z_DOWN 7
# define MOVE_UP 125
# define MOVE_DOWN 126
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define ESC 53

# define RAD 0.09174533

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	sx;
	int	sy;
}				t_point;

typedef struct	s_dpoint
{
	double		x;
	double		y;
	double		z;
	int			color;
	int			sx;
	int			sy;
}				t_dpoint;

typedef struct	s_size
{
	int			n;
	int			m;
}				t_size;

typedef struct	s_cam
{
	t_point		position;
	double		proj_per_k;
}				t_cam;

typedef struct	s_map
{
	t_dpoint	**canvas;
	t_dpoint	**cnv_trm;
	t_size		d;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*buffer;
	int			*zbuffer;
	double		scale;
	t_dpoint	angl;
	double		z_h;
	t_size		shift;
	int			projection;
	t_cam		cam;
	int			*c_gr;
}				t_map;

typedef struct		s_mlxadr
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlxadr;

int			fdf_init(int fd, t_map *map);
t_dpoint	**ft_read(int fd, t_map *map);
t_dpoint	**ft_create_matrd(int n, int m);
int			fdf_pix_to_buf(int x, int y, int color, t_map *map);
void		destroy_split(char **st);

void		fdf_exit(t_map *map);
void		transform(t_map *map);
void		rotation(t_map *map);
void		rot_z(t_map *map, double alpha, t_dpoint **array);
void		rot_y(t_map *map, double alpha, t_dpoint **array);
void		rot_x(t_map *map, double alpha, t_dpoint **array);
void		up_mod(t_map *map);
void		iso_mod(t_map *map);
void		persp_mod(t_map *map);
void        zoom_z(int key, t_map *map);

void		draw(t_map *map);
void		draw_map(t_map map);
void		draw_line(t_dpoint point0, t_dpoint point1, t_map *map);
void		draw_menu(t_map *map);

int			key_hook(int key, void *param);
void		reset(t_map *map);
void		fdf_change_projection(int key, t_map *map);

int			fdf_create_img_win(t_map *map);
int			fdf_def_sizel(t_map *map);
int			dist(t_dpoint p1, t_dpoint p2);
void		del_list(void *s, size_t size);

int			ft_abs(int a);
int			word_count(char const *s, char c);
void		ft_lstaddback(t_list **alst, t_list *new);
int			get_next_line(const int fd, char **line);
int			print_error(int i);
void		print_error_exit(int i, t_map *map);

#endif
