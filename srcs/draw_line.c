#include "fdf.h"

static t_point		d_point(t_dpoint pt0, t_dpoint pt1)
{
	t_point			d;

	d.x = ft_abs(pt1.sx - pt0.sx);
	d.y = ft_abs(pt1.sy - pt0.sy);
	return (d);
}

static t_point		p_sign(t_dpoint pt0, t_dpoint pt1)
{
	t_point			sign;

	sign.x = pt0.sx < pt1.sx ? 1 : -1;
	sign.y = pt0.sy < pt1.sy ? 1 : -1;
	return (sign);
}

int			fdf_pix_to_buf(int x, int y, int color, t_map *map)
{
	if (x < 0)
		return (0);
	((y * WIN_WIDTH + x) < (y + 1) * WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT) ?
					map->buffer[(int)((y * WIN_WIDTH + x))] = color : 1;
	return (1);
}

void				draw_line(t_dpoint pt0, t_dpoint pt1, t_map *map) // рисуем по Брейзенхайму
{
	t_point			d;
	t_point			sign;
	t_point			er;

	d = d_point(pt0, pt1); // разница координат
	sign = p_sign(pt0, pt1); // шаг
	er.x = d.x - d.y;
	while (pt0.sx != pt1.sx || pt0.sy != pt1.sy)
	{
		fdf_pix_to_buf(pt0.sx, pt0.sy, COLOR_LINE, map);
		er.y = er.x * 2;
		if (er.y > -d.y)
		{
			er.x -= d.y;
			pt0.sx += sign.x;
		}
		if (er.y < d.x)
		{
			er.x += d.x;
			pt0.sy += sign.y;
		}
	}
}
