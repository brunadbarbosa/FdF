/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:29:54 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/28 10:58:52 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

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

int	main(int argc, char **argv)
{
	t_view	*view;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <file.fdf>\n", 24);
		return (1);
	}
	view = malloc(sizeof(t_view));
	parse(argv[1], view);
	init_view(view);
	draw_map(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	print_commands(view);
	mlx_mouse_hook(view->win, mouse_hook, view);
	mlx_key_hook(view->win, keyboard, view);
	mlx_hook(view->win, 17, 0, win_close, view);
	mlx_loop(view->mlx);
	free_map(view);
	free(view);
}

