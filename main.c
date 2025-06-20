#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;

#define WIDTH 1920
#define HEIGHT 1024

int close_esc(int  key, t_data **env);
int close_x(t_data **env);

void	init_data(t_data **env);
void	init_img(t_img *img, t_data **env);

void	free_data(t_data **env, int status);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_img *img);

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


int x_(int x, int y, int z)
{
	double	out;

	out = (WIDTH / 2) - ((x - z) * sin(30));
	return ((int)out);
}

int y_(int x, int y, int z)
{
	double	out;
	// out = (HEI - 40) - y - ((x + z) * cos(30));

	out = (HEIGHT / 2) - y - ((x + z) * cos(30));
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
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0xFFFFFFFF);
			x1++;
		}
	}
	if (y1 < y2)
	{
		while (y1 != y2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0xFFFFFFFF);
			y1++;
		}
	}
	if (z1 < z2)
	{
		while (z1 != z2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0xFFFFFFFF);
			z1++;
		}
	}
}

void	draw_lin1(t_img *img,int x1, int y1, int z1, int x2, int y2, int z2)
{
	if (x1 < x2)
	{
		while (x1 != x2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x000000FF);
			x1++;
		}
	}
	if (y1 < y2)
	{
		while (y1 != y2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x000000FF);
			y1++;
		}
	}
	if (z1 < z2)
	{
		while (z1 != z2)
		{
			my_pixel_put(img, x_(x1,y1,z1), y_(x1,y1,z1), 0x000000FF);
			z1++;
		}
	}
}

void	draw(t_img *img)
{
	char *map[] = {
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
		NULL
	};

	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			my_pixel_put(img, x_(i*20,j%2*20,ft_atoi(&map[i][j])*20), y_(i*20,j%2*20,ft_atoi(&map[i][j])*20), 0xFFFFFFFF);
			// draw_line(img, (i)*20,(j-1)*20,ft_atoi(&map[i][j-1])*20, i,j,ft_atoi(&map[i][j]));
			j+=2;
		}
		i++;
	}
	// draw_line(img, 0,0,0, 500,0,0);
	// draw_line(img, 0,500,0, 500,500,0);
	// draw_line(img, 0,0,0, 0,500,0);
	// draw_line(img, 500,0,0, 500,500,0);
	// draw_line(img, 0,0,0, 0,0,500);
	// draw_line(img, 0,0,500, 0,500,500);
	// draw_line(img, 0,500,500, 500,500,500);
	// draw_line(img, 500,500,0, 500,500,500);
	// draw_line(img, 0,500,0, 0,500,500);
	// draw_line(img, 0,500,500, 500,500,500);
}

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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*px1;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		px1 = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)px1 = color;
	}
}
