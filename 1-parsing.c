/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:58:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/07 13:24:42 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int	check_width(char **split, int expected)
{
	int	i;

	i = 0;
	while (split[i] && split[i][0] != '\n')
		i++;
	return (i == expected);
}

static int	get_width(char *file)
{
	int		fd;
	char	c;
	int		width;

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
	int		height;
	int		in_line;
	int		fd;

	height = 0;
	in_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
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
	if (in_line)
		height++;
	close(fd);
	return (height);
}

int	atoi_hex(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else
			break ;
		i++;
	}
	return (result);
}

void	parse(char *file, t_view *view)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	i = -1;
	view->width = get_width(file);
	view->height = get_height(file);
	view->map = malloc(sizeof(t_point *) * view->height);
	fd = open(file, O_RDONLY);
	if (!view->map || fd < 0)
		error_fd(view);
	line = get_next_line(fd);
	while (line != NULL)
	{
		view->map[++i] = malloc(sizeof(t_point) * view->width);
		if (!view->map[i])
			error_fd(view);
		split = ft_split(line, ' ');
		add_measures(view, split, i);
		free_split(split);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
