/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-screen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:18:00 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/21 13:18:13 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	handle_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void draw_horizontal_line(void *mlx, void *win, int y)
{
	int x;

	x = 0;
	while (x < 800)
	{
		mlx_pixel_put(mlx, win, x, y, 0xFF0000);
		x++;
	}
}

void draw_diagonal_line(void *mlx, void *win)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 800 && y < 600)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FF00);
		x++;
		y++;
	}
}

void draw_vertical_line(void *mlx, void *win, int x)
{
	int y;

	y = 0;
	while (y < 800)
	{
		mlx_pixel_put(mlx, win, x, y, 0xFF0000);
		y++;
	}
}