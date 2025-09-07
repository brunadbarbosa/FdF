/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:35:07 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/07 14:06:31 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_view
{
	t_point	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		zoom;
	int		z_scale;
	int		x_offset;
	int		y_offset;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_view;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

int		check_width(char **split, int expected);
void	parse(char *file, t_view *view);
int		atoi_hex(const char *str);
void	add_measures(t_view *view, char **split, int i);
void	free_map(t_view *view);
void	free_split(char **tokens);
void	draw_pixel(t_view *img, int x, int y, int color);
void	clear_image(t_view *view);
void	draw_line(t_view *img, t_point a, t_point b, int color);
int		handle_keypress(int keycode, t_view *vars);
int		handle_close(t_view *vars);
void	draw_line(t_view *view, t_point a, t_point b, int color);
void	draw_map(t_view *view);
void	rotate_x(double *y, double *z, double angle_x);
void	rotate_y(double *x, double *z, double angle_y);
void	rotate_z(double *x, double *y, double angle_z);
void	error(void);
void	error_fd(t_view *view);

#endif