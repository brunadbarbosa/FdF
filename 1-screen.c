/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-screen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:18:00 by brmaria-          #+#    #+#             */
/*   Updated: 2025/08/21 16:40:39 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_view *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	clear_image(t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(view, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

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

void isometric_projection(t_point *p)
{
	int prev_x = p->x;
	int prev_y = p->y;

	p->x = (prev_x - prev_y) * cos(0.523599);
	p->y = (prev_x + prev_y) * sin(0.523599) - p->z;
}

int	handle_keypress(int keycode, t_view *view)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(view->mlx, view->win);
		exit(0);
	}
	else if (keycode == 65361) // left arrow
		view->angle_y -= 0.05;
	else if (keycode == 65363) // right arrow
		view->angle_y += 0.05;
	else if (keycode == 65362) // up arrow
		view->angle_x -= 0.05;
	else if (keycode == 65364) // down arrow
		view->angle_x += 0.05;
	else if (keycode == 119) // w
		view->y_offset -= 10;
	else if (keycode == 115) // a
		view->y_offset += 10;
	else if (keycode == 97) // s
		view->x_offset -= 10;
	else if (keycode == 100) // d
		view->x_offset += 10;
	printf("%d\n", keycode);
	clear_image(view);
	draw_map(view);
	return (0);
}

int	handle_close(t_view *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	draw_line(t_view *img, t_point a, t_point b, int color)
{
	float	step;
	float	x;
	float	y;
	float	dx = b.x - a.x;
	float	dy = b.y - a.y;

	step = fmax(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	x = a.x;
	y = a.y;
	while ((int)(x - b.x) || (int)(y - b.y))
	{
		draw_pixel(img, x, y, color);
		x += dx;
		y += dy;
	}
}

t_point get_projected_point(t_point original, t_view *view)
{
    t_point projected;

    projected.x = original.x * view->zoom;
    projected.y = original.y * view->zoom;
    projected.z = original.z * view->z_scale;

    rotate_x(&projected.y, &projected.z, view->angle_x);
    rotate_y(&projected.x, &projected.z, view->angle_y);
    rotate_z(&projected.x, &projected.y, view->angle_z);

    isometric_projection(&projected);

    projected.x += view->x_offset;
    projected.y += view->y_offset;

    return (projected);
}

// Versão refatorada da função draw_map
void    draw_map(t_view *view)
{
    int     x;
    int     y;
    t_point a;
    t_point b;

    y = 0;
    while (++y < view->height)
    {
        x = 0;
        while (++x < view->width)
        {
            a = get_projected_point(view->map[y][x], view);
            if (x < view->width - 1)
            {
                b = get_projected_point(view->map[y][x + 1], view);
                draw_line(view, a, b, 0xFFFFFF);
            }
            if (y < view->height - 1)
            {
                b = get_projected_point(view->map[y + 1][x], view);
                draw_line(view, a, b, 0xFFFFFF);
            }
        }
    }
    mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
}
