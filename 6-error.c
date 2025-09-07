/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:09:16 by brmaria-          #+#    #+#             */
/*   Updated: 2025/09/06 13:51:30 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(void)
{
	printf("Error: cannot open file.\n");
	exit(EXIT_FAILURE);
}

void	error_fd(t_view *view)
{
	printf("Error: cannot open file.\n");
	free_map(view);
	free(view);
	exit(EXIT_FAILURE);
}
