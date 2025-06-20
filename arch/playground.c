#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
#define colx 0xFFFFFFFF




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

int x_(int x, int y, int z)
{
	double	out;

	out = (WID / 2) - ((x - z) * sin(30));
	return ((int)out);
}

int y_(int x, int y, int z)
{
	double	out;
	// out = (HEI - 40) - y - ((x + z) * cos(30));

	out = (HEI / 2) - y - ((x + z) * cos(30));
	return ((int)out);
}

// void	render(t_img *img)
// {

	// int	pt_1[] = { 0,  0,  0};
	// int	pt_2[] = {20,  0,  0};
	// int	pt_3[] = { 0, 20,  0};
	// int	pt_4[] = {20, 20,  0};
	// int	pt_5[] = { 0,  0, 20};
	// int	pt_6[] = {20,  0, 20};
	// int	pt_7[] = { 0, 20, 20};
	// int	pt_8[] = {20, 20, 20};

	// int x = 0;
	// int y = 0;
	// int z = 0;

	// while (x < 80)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	x++;
	// }
	// while (y < 80)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	y++;
	// }
	// while (x > 0)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	x--;
	// }
	// while (y > 0)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	y--;
	// }
	// while (z < 80)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	z++;
	// }
	// while (y < 80)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	y++;
	// }
	// while (z > 0)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	z--;
	// }
	// z = 80;
	// while (x < 80)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	x++;
	// }
	// while (z > 0)
	// {
	// 	my_pixel_put(img, x_(x, y, z), y_(x, y, z), RED);
	// 	z--;
	// }
	// my_pixel_put(img, x_(pt_2), y_(pt_2), RED);
	// my_pixel_put(img, x_(pt_3), y_(pt_3), RED);
	// my_pixel_put(img, x_(pt_4), y_(pt_4), RED);
	// my_pixel_put(img, x_(pt_5), y_(pt_5), RED);
	// my_pixel_put(img, x_(pt_6), y_(pt_6), RED);
	// my_pixel_put(img, x_(pt_7), y_(pt_7), RED);
	// my_pixel_put(img, x_(pt_8), y_(pt_8), RED);
// }

// void	render(t_img *img)
// {
// 	int pt1[] = {0,0,0};
// 	int pt2[] = {20,0,0};
// 	int pt3[] = {0,20,0};
// 	int pt4[] = {20,20,0};
	
// 	int pt5[] = {0,0,20};
// 	int pt6[] = {20,0,20};
// 	int pt7[] = {0,20,20};
// 	int pt8[] = {20,20,20};
// 	my_pixel_put(img, 0, 10, RED);
// 	my_pixel_put(img, 20, 10, RED);
// 	my_pixel_put(img, 0, 30, RED);
// 	my_pixel_put(img, 20, 30, RED);

// 	my_pixel_put(img, 10, 0, RED);
// 	my_pixel_put(img, 30, 0, RED);
// 	// my_pixel_put(img, 10, 20, RED);
// 	my_pixel_put(img, 30, 20, RED);
// }

void	render(t_img *img)
{
	char *map[]= {
"00000000000000000000",
"00000000000000000000",
"00000000000000000000",
"00055000000055500000",
"00055000000055550000",
"00055000000550555000",
"00055000000550055000",
"00055000000550055000",
"00055000000000055000",
"00055555000000555000",
"00055555000005550000",
"00055555000055500000",
"00000550000555000000",
"00000550000550000000",
"00000550000555555000",
"00000550000555555000",
"00000550000555555000",
"00000000000000000000",
"00000000000000000000",
"00000000000000000000",
NULL
};
// char *map[] = {
// "00112233445566778899",
// "00001122334455667788",
// "00000011223344556677",
// "00000000112233445566",
// "00000000001122334455",
// "00000000000011223344",
// "00000000000000112233",
// "00000000000000001122",
// "00000000000000000011",
// NULL
// };
// 	char *map[] = {
// "000000000000000000000000000",
// "000001111111111111111100000",
// "000001222222222222222100000",
// "000001233333333333332100000",
// "000001234444444444432100000",
// "000001234444444444432100000",
// "000001234444444444432100000",
// "000001234444444444432100000",
// "000001234444444444432100000",
// "000001234555555555432100000",
// "000001234566666665432100000",
// "000001234567777765432100000",
// "000001234567888765432100000",
// "000001234567888765432100000",
// "000001234567888765432100000",
// "000001234567888765432100000",
// "000001234567898765432100000",
// "000001234567888765432100000",
// "000001234567777765432100000",
// "000001234566666665432100000",
// "000001234555555555432100000",
// "000001234444444444432100000",
// "000001233333333333332100000",
// "000001222222222222222100000",
// "000001111111111111111100000",
// "000000000000000000000000000",
// 	NULL};
	int row = 0;
	while (map[row])
		row++;

	int fac = 30;
	int width = WID / (int)strlen(map[0]);
	int height = HEI /row;
	if (width <= height)
		fac = width;
	else
		fac = height;

	size_t	i = 0;
	size_t	j = 0;
		int colllx;
			colllx = 0xFFFFFFFF;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			int o = 0;
			while (o < 10)
			{
			if (map[i][j] == '0' + o)
				{
					if (map[i][j+1] == '0' + o)
					{
						int l = j * fac;
						while (l < j * fac + fac)
						{
							my_pixel_put(img, l, i * fac, colllx);
							l++;
						}
					}
					if (map[i + 1] && map[i+1][j] == '0' + o)
						{
							int k = i * fac;
							while (k < i * fac + fac)
							{
								my_pixel_put(img, j * fac, k, colllx);
								k++;
							}
					}

				}
				o++;
			}

		
			my_pixel_put(img, j * fac    , i * fac,     RED);
			my_pixel_put(img, j * fac + 1, i * fac,     RED);
			my_pixel_put(img, j * fac + 2, i * fac,     RED);
			my_pixel_put(img, j * fac    , i * fac + 1, RED);
			my_pixel_put(img, j * fac + 1, i * fac + 1, RED);
			my_pixel_put(img, j * fac + 2, i * fac + 1, RED);
			my_pixel_put(img, j * fac    , i * fac + 2, RED);
			my_pixel_put(img, j * fac + 1, i * fac + 2, RED);
			my_pixel_put(img, j * fac + 2, i * fac + 2, RED);
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