/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:19:21 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/27 17:51:13 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int x_(int x, int y, int z)
{
	double	out;

	out = (WIDTH / 2) + ((x - y) * sin(30));	
	return ((int)out);
}

int y_(int x, int y, int z)
{
	double	out;

	out = (HEIGHT / 2) - z + ((x + y) * cos(30));
	return ((int)out);
}

// Template
	// my_pixel_put(img, x_(0,0,0), y_(0,0,0), 0x00FF0000);


void	draw_line(t_img *img,int x1, int y1, int z1, int x2, int y2, int z2)
{
	if (x1 < x2)
	{
		while (x1 != x2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			x1++;
		}
	}
	else
	{
		while (x1 != x2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			x1--;
		}
	}
	if (y1 < y2)
	{
		while (y1 != y2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			y1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			y1--;
		}
	}
	if (z1 < z2)
	{
		while (z1 != z2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			z1++;
		}
	}
	else
	{
		while (z1 != z2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x00FF0000);
			z1--;
		}
	}
}

// void	draw(t_img *img)
// {
// 	char *map[] = {
// 		"3210",
// 		"2100",
// 		"1000",
// 		NULL
// 	};
// }


void	draw(t_img *img)
{

	char **map;

	map = get_map("maps/42.fdf");
	size_t	i;
	size_t	j;
	
	int	x1 = 0;
	int	y1 = 0;
	int	z1 = 0;
	int	x2 = 1;
	int	y2 = 0;
	int	z2 = 0;
	int scale = 100;
	// my_pixel_put(img, x_(0,0,0), y_(0,0,0), 0xFFFFFFFF);
	draw_line(img, x1 * scale, y1 * scale, z1 * scale, x2 *scale, y2* scale, z2 * scale);

// i = 0;
// while (map[i])
// {
// 	j = 0;
// 	while (map[i][j])
// 	{
// 		// if (map[i][j] == '0')
// 			my_pixel_put(img, x_(i*20,j/2*20,ft_atoi(&map[i][j])*20), y_(i*20,j/2*20,ft_atoi(&map[i][j])*20), 0xFFFFFFFF);
// 			// draw_line(img, (i)*20,(j-1)*20,ft_atoi(&map[i][j-1])*20, i,j,ft_atoi(&map[i][j]));
// 			j++;
// 	}
// 	i++;
// }
}
