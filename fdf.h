/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:35:07 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/21 17:39:54 by brmaria-         ###   ########.fr       */
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
	int	**map;
	int x;
	int y;
	int z;
}	t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

#endif