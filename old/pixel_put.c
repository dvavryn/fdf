/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:29 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/23 15:21:41 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*px1;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		px1 = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)px1 = color;
	}
}