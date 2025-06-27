#include <mlx.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

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

char **get_map(char *path);
char *get_oneline(char *path);
