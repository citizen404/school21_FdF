#include "fdf.h"

t_point				**ft_create_matr(int n, int m) //память под массив точек инт
{
	int			i;
	t_point			**matr;

	i = -1;
	if ((matr = (t_point**)malloc(sizeof(t_point*) * n)) == NULL)
		return (NULL);
	else
		while (++i < n) //если выделить не удалось, освобождаем память
		{
			if ((matr[i] = (t_point*)malloc(sizeof(t_point) * m)) == NULL)
				while (--i >= 0)
					free(matr[i]);
		}
	return (matr);
}

t_dpoint			**ft_create_matrd(int n, int m) //память под массив точек дабл
{
	int			i;
	t_dpoint		**matr;

	i = -1;
	if ((matr = (t_dpoint**)malloc(sizeof(t_dpoint*) * n)) == NULL)
		return (NULL);
	else
		while (++i < n) //если выделить не удалосьб освобождаем память
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
			mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")) == NULL) //привязка окна
		return (print_error(5));
	if ((map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL) //привязка изображения
		return (print_error(5));
	return (1);
}

