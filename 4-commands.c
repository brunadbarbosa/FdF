/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:20:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/07 13:47:49 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_close(t_view *view)
{
	mlx_destroy_image(view->mlx, view->img);
	mlx_destroy_window(view->mlx, view->win);
	mlx_destroy_display(view->mlx);
	free(view->mlx);
	free_map(view);
	free(view);
	exit(0);
	return (0);
}

int	handle_keypress2(int keycode, t_view *view)
{
	if (keycode == 45)
		view->zoom--;
	else if (keycode == 105)
		view->z_scale++;
	else if (keycode == 117)
		view->z_scale--;
	return (0);
}

int	handle_keypress(int keycode, t_view *view)
{
	if (keycode == 65307)
		handle_close(view);
	else if (keycode == 65361)
		view->angle_y -= 0.05;
	else if (keycode == 65363)
		view->angle_y += 0.05;
	else if (keycode == 65362)
		view->angle_x -= 0.05;
	else if (keycode == 65364)
		view->angle_x += 0.05;
	else if (keycode == 119)
		view->y_offset -= 10;
	else if (keycode == 115)
		view->y_offset += 10;
	else if (keycode == 97)
		view->x_offset -= 10;
	else if (keycode == 100)
		view->x_offset += 10;
	else if (keycode == 61)
		view->zoom++;
	else
		handle_keypress2(keycode, view);
	clear_image(view);
	draw_map(view);
	return (0);
}
