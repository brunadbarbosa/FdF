/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:09:16 by brmaria-          #+#    #+#             */
/*   Updated: 2025/08/21 17:11:44 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_fd(t_view *view)
{
	ft_printf("Error: cannot open file.\n");
	free_map(view);
	free(view);
	exit(1);
}