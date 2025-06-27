/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:38:12 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 14:44:46 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closing(int key, t_data **env)
{
	if (key == 65307)
		mlx_loop_end((*env)->mlx);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*env;

	if (argc != 2)
		error_exit("Usage: ./fdf <map.fdf>", 1);
	init_data(&env, argv[1]);

	for(int i = 0; env->map[i]; i++)
	{
		ft_printf("%s\n", env->map[i]);
	}

	t_img	img;
	img.img = mlx_new_image(env->mlx, WID, HEI);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	my_draw_line(&img, 10, 10, 10, 20, 0x00FF0000);
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);	


	mlx_hook(env->win, 2, 1L << 0, closing, &env);
	mlx_hook(env->win, 17, 1L << 2, mlx_loop_end, env->mlx);
	mlx_loop(env->mlx);
	free_data(&env);
}
