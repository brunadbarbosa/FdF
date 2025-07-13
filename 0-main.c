/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:29:54 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/13 12:15:12 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		x++;
	}
}

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Teste da Tela");

	draw_horizontal_line(mlx, win, 300);
	draw_diagonal_line(mlx, win);
	draw_vertical_line(mlx, win, 600);

	mlx_loop(mlx);
	return (0);
}