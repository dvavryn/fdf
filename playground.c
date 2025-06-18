#include <mlx.h>
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
}	t_data;

#define WID 800
#define HEI 800

void	my_pixel_put(t_img *img, int x, int y, int color);
void	my_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);

int closing (int key, t_data *mlx);

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0xFFFFFFFF




void	draw_hor(t_img *img, int *xy1, int *xy2)
{
	while (xy1[0] < xy2[0])
	{
		my_pixel_put(img, xy1[0], xy1[1], RED);
		xy1[0]++;
	}
}

void	draw_ver(t_img *img, int *xy1, int *xy2)
{
	while (xy1[1] < xy2[1])
	{
		my_pixel_put(img, xy1[0], xy1[1], RED);
		xy1[1]++;
	}
}

void	draw_45(t_img *img, int *xy1, int *xy2)
{
	if (xy1[0] < xy2[0])
	{
		while (xy1[0] < xy2[0] && xy1[1] < xy2[1])
		{
			my_pixel_put(img, xy1[0], xy1[1], RED);
			xy1[0]++;
			xy1[1]++;
		}
	}
	else
	{
		while (xy1[0] > xy2[0] && xy1[1] < xy2[1])
		{
			my_pixel_put(img, xy1[0], xy1[1], RED);
			xy1[0]--;
			xy1[1]++;
		}
	}
}


#define XX 30
void	render(t_img *img)
{
	char *map[] = {
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
"000001111111111111111100000",
"000001222222222222222100000",
"000001233333333333332100000",
"000001234444444444432100000",
"000001234444444444432100000",
"000001234444444444432100000",
"000001234444444444432100000",
"000001234444444444432100000",
"000001234555555555432100000",
"000001234566666665432100000",
"000001234567777765432100000",
"000001234567888765432100000",
"000001234567888765432100000",
"000001234567888765432100000",
"000001234567888765432100000",
"000001234567898765432100000",
"000001234567888765432100000",
"000001234567777765432100000",
"000001234566666665432100000",
"000001234555555555432100000",
"000001234444444444432100000",
"000001233333333333332100000",
"000001222222222222222100000",
"000001111111111111111100000",
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
"000000000000000000000000000",
	NULL};
	
	size_t	i = 0;
	size_t	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (map[i][j+1] == '0')
				{
					int l = j * XX;
					while (l < j * XX + XX)
					{
						my_pixel_put(img, l, i * XX, WHITE);
						l++;
					}
				}
				if (map[i + 1] && map[i+1][j] == '0')
					{
						int k = i * XX;
						while (k < i * XX + XX)
						{
							my_pixel_put(img, j * XX, k, WHITE);
							k++;
						}
				}

			}
			if (map[i][j] == '1')
			{
				if (map[i][j+1] == '1')
				{
					int l = j * XX;
					while (l < j * XX + XX)
					{
						my_pixel_put(img, l, i * XX, WHITE);
						l++;
					}
				}
				if (map[i + 1] && map[i+1][j] == '1')
					{
						int k = i * XX;
						while (k < i * XX + XX)
						{
							my_pixel_put(img, j * XX, k, WHITE);
							k++;
						}
				}

			}
		
			my_pixel_put(img, j * XX    , i * XX,     RED);
			my_pixel_put(img, j * XX + 1, i * XX,     RED);
			my_pixel_put(img, j * XX + 2, i * XX,     RED);
			my_pixel_put(img, j * XX    , i * XX + 1, RED);
			my_pixel_put(img, j * XX + 1, i * XX + 1, RED);
			my_pixel_put(img, j * XX + 2, i * XX + 1, RED);
			my_pixel_put(img, j * XX    , i * XX + 2, RED);
			my_pixel_put(img, j * XX + 1, i * XX + 2, RED);
			my_pixel_put(img, j * XX + 2, i * XX + 2, RED);
			j++;
		}
		i++;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

int main(int argc, char **argv)
{
	t_data env;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WID, HEI, "playground");
	t_img	img;
	img.img = mlx_new_image(env.mlx, WID, HEI);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);




	render(&img);


	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 10);

	mlx_hook(env.win, 2, 1L << 0, closing, &env);
	mlx_hook(env.win, 17, 1L << 2, mlx_loop_end, env.mlx);
	mlx_loop(env.mlx);
}











int closing (int key, t_data *mlx)
{
	if (key == 65307 || key == 'b')
		mlx_loop_end(mlx->mlx);
	return (0);
}

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
	if (!step)
		return ;
    delta_x = delta_x / step;
    delta_y = delta_y / step;
    x = x1;
    y = y1;
    i = 0;
    while (i < step)
    {
        my_pixel_put(img, x, y, color);
        x += delta_x;
        y += delta_y;
        i++;
    }
}