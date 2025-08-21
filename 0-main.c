/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:29:54 by brmaria-          #+#    #+#             */
/*   Updated: 2025/08/21 14:17:29 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

void	init_view(t_view *view)
{
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF 2D Viewer");
	view->zoom = 20;
	view->angle_x = 0;
	view->angle_y = 0;
	view->angle_z = 0;
	view->z_scale = 3;
	view->x_offset = WIN_WIDTH / 2;
	view->y_offset = WIN_HEIGHT / 4;
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->addr = mlx_get_data_addr(view->img, &view->bpp, &view->line_length, &view->endian);
}

void free_split(char **tokens)
{
	int i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_map(t_view *view)
{
	int i;

	if (!view || !view->map)
		return;

	for (i = 0; i < view->height; i++)
		free(view->map[i]);
	free(view->map);
	view->map = NULL;
}


int	main(int argc, char **argv)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (argc != 2)
	{
		printf("Usage: ./fdf <map_file>\n");
		return (1);
	}
	parse(argv[1], view);
	init_view(view);
	draw_map(view);

	mlx_key_hook(view->win, handle_keypress, view);
	mlx_hook(view->win, 17, 0, handle_close, view);
	mlx_loop(view->mlx);
	
	free_map(view);
	free(view);
	return (0);
}
