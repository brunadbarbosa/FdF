/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:29:54 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/10 20:57:26 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 800, 600, "Teste MiniLibX");
    if (!win)
        return (1);

    mlx_pixel_put(mlx, win, 500, 10, 0xFF0000);
    mlx_loop(mlx);
    return (0);
}