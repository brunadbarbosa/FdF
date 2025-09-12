/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-screen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:18:00 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/10 12:22:50 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	direction(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	init_bresenham(t_bresenham *b, t_point a, t_point b_point)
{
	b->dx = fabs(b_point.x - a.x);
	b->dy = fabs(b_point.y - a.y);
	b->sx = direction(a.x, b_point.x);
	b->sy = direction(a.y, b_point.y);
	b->err = b->dx - b->dy;
}

void	isometric_projection(t_point *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(0.523599);
	p->y = (prev_x + prev_y) * sin(0.523599) - p->z;
}

t_point	get_projected_point(t_point original, t_view *view)
{
	t_point	projected;

	projected.x = original.x * view->zoom;
	projected.y = original.y * view->zoom;
	projected.z = original.z * view->z_scale;
	rotate_x(&projected.y, &projected.z, view->angle_x);
	rotate_y(&projected.x, &projected.z, view->angle_y);
	rotate_z(&projected.x, &projected.y, view->angle_z);
	isometric_projection(&projected);
	projected.x += view->x_offset;
	projected.y += view->y_offset;
	projected.color = original.color;
	return (projected);
}

void	draw_map(t_view *view)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			a = get_projected_point(view->map[y][x], view);
			if (x < view->width - 1)
			{
				b = get_projected_point(view->map[y][x + 1], view);
				draw_line(view, a, b, a.color);
			}
			if (y < view->height - 1)
			{
				b = get_projected_point(view->map[y + 1][x], view);
				draw_line(view, a, b, a.color);
			}
		}
	}
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
}
