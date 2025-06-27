/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:22:12 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/23 15:22:21 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_img *img, t_data **env)
{
	img->img = mlx_new_image((*env)->mlx, WIDTH, HEIGHT);
	if (!img->img)
		free_data(env, 4);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
	{
		mlx_destroy_image((*env)->mlx, img->img);
		free_data(env, 5);
	}
}

void	init_data(t_data **env)
{
	(*env) = malloc(sizeof(t_data));
	if (!*env)
		free_data(env, 1);
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
		free_data(env, 2);
	(*env)->win = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "stefan");
	if (!(*env)->win)
		free_data(env, 3);
}

void	free_data(t_data **env, int status)
{
	if ((*env)->win)
		mlx_destroy_window((*env)->mlx, (*env)->win);
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if (*env)
		free(*env);
	exit (status);
}

int close_esc(int  key, t_data **env)
{
	if (key == 65307 || key == ' ')
		free_data(env, 0);
	return 0;
}

int close_x(t_data **env)
{
	free_data(env, 0);
	return 0;
}


