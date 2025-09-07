/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-drawImage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:44:04 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/07 13:32:12 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	add_measures(t_view *view, char **split, int i)
{
	int		j;
	char	**z_color;

	j = 0;
	while (j < view->width)
	{
		z_color = ft_split(split[j], ',');
		view->map[i][j].x = j;
		view->map[i][j].y = i;
		view->map[i][j].z = ft_atoi(z_color[0]);
		if (z_color[1])
			view->map[i][j].color = atoi_hex(z_color[1]);
		else
			view->map[i][j].color = 0XFFFFFF;
		printf("%d", view->map[i][j].color);
		free_split(z_color);
		j++;
	}
}

void	draw_pixel(t_view *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1000 || y >= 800)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1000)
		{
			draw_pixel(view, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_line(t_view *img, t_point a, t_point b, int color)
{
	float	step;
	float	x;
	float	y;
	float	dx;
	float	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
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
