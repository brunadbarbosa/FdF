/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:29:54 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/21 19:51:11 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	fd;
	char	*gnl;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(2, "I need only one file!\n", 22);
		return(1);
	}
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		char **split = ft_split(gnl, ' ');
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (gnl)
		free(gnl);
	close (fd);
	return (0);
}
