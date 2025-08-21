/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/08/21 16:41:33 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int check_width(char **split, int expected)
{
	int i = 0;
	while (split[i] && split[i][0] != '\n')
		i++;
	return (i == expected);
}

static int	get_width(char *file)
{
	int	fd;
	char	c;
	int	width;

	width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if ((c >= '0' && c <= '9') || c == '-')
		{
			width++;
			while (c != ' ' && c != '\n')
				read(fd, &c, 1);
		}
		if (c == '\n')
			break ;
	}
	close(fd);
	return (width);
}

static int	get_height(char *file)
{
	char	c;
	int	height;
	int	in_line;
	int	fd;
	
	height = 0;
	in_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			height++;
			in_line = 0;
		}
		else
			in_line = 1;
	}
	if(in_line)
		height++;
	close(fd);
	return (height);
}

static void	add_measures(t_view *view, char **split, int i)
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
		// if (z_color[1])
		// 	view->map[i][j].color = atoi_hex(z_color[1]);
		// else
		// 	view->map[i][j].color = 0;
		free_split(z_color);
		j++;
	}
}

void	parse(char *file, t_view *view)
{
	int		fd;
	int		i = 0;
	char	*line;
	char	**split;

	view->width = get_width(file);
	view->height = get_height(file);
	view->map = malloc(sizeof(t_point *) * view->height);
	if (!view->map)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		view->map[i] = malloc(sizeof(t_point) * view->width);
		if (!view->map[i])
			exit(EXIT_FAILURE);
		split = ft_split(line, ' ');
		add_measures(view, split, i);
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
