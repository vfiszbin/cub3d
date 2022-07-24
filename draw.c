/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:55:55 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/07/24 16:56:56 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	custom_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img1.addr + (y * vars->img1.line_length + x
			* (vars->img1.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return *(unsigned int*)color;
}

void draw_vertical_line(t_vars *vars, int x, int begin_y, int end_y, int color)
{
	double pixelY;
	int pixels_to_draw;
	
	pixels_to_draw = end_y - begin_y;
	pixelY = begin_y;
	while (pixels_to_draw)
	{
		custom_mlx_pixel_put(vars, x, pixelY, color);
		pixelY += 1;
		pixels_to_draw--;
	}
}