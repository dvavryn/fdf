#include <mlx.h>
#include "../libft/libft.h"


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;


int close_esc(int  key, t_data **env);
int close_x(t_data **env);

void	init_data(t_data **env);
void	free_data(t_data **env, int status);
int main(int argc, char **argv)
{
	t_data *env;

	init_data(&env);

	mlx_key_hook(env->win, close_esc, &env);
	mlx_hook(env->win, 17, 1L << 2, close_x, &env);
	mlx_loop(env->mlx);
}


void	init_data(t_data **env)
{
	(*env) = malloc(sizeof(t_data));
	if (!*env)
		free_data(env, 1);
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
		free_data(env, 2);
	(*env)->win = mlx_new_window((*env)->mlx, 800, 800, "stefan");
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