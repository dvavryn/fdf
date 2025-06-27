#include "fdf.h"

int main(int argc, char **argv)
{
	t_data *env;
	t_img	img;

	init_data(&env);
	init_img(&img, &env);

	draw(&img);

	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_key_hook(env->win, close_esc, &env);
	mlx_hook(env->win, 17, 1L << 2, close_x, &env);
	mlx_loop(env->mlx);
}
