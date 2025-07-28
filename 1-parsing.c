/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/28 16:13:04 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
	fd = open(fd, O_RDONLY);
	if (fd < 0)
		return (-1);
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
	
}

void	parse(char *file, t_view *view)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	view->width = get_width(file);
	view->height = get_height(file);
	view->map = malloc(sizeof(t_point *) * view->height);
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		view->map[i] = malloc(sizeof(t_point) * view->width);
		split = ft_split(line, ' ');
		add_measures(view, split, i);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
