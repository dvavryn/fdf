/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:50 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 12:30:42 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*px1;
	if (x >= 0 && x < WID && y >= 0 && y < HEI)
	{
		px1 = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)px1 = color;
	}
	
}

void	my_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	int step;
	int x;
	int y;
	int i;
	int delta_x;
	int delta_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (abs(delta_x) >= abs(delta_y))
		step = abs(delta_x);
	else
		step = abs(delta_y);
	delta_x = delta_x / step;
	delta_y = delta_y / step;
	x = x1;
	y = x2;
	i = 0;
	while (i < step)
	{
		my_pixel_put(img, y, y, color);
		x += delta_x;
		y += delta_y;
		i++;
	}
}