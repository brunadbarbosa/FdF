/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:35:07 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/24 14:47:05 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_point {
	int x;
	int y;
	int z;
}	t_point;

typedef struct s_map {
	t_point **points;
	int width;
	int height;
}	t_map;

typedef struct s_view {
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_view;

#endif