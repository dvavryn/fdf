#include <mlx.h>
#include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

void	error_exit(char *msg, int status)
{
	write(2, "ERROR\n", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(status);
}

void	check_path(char *path)
{
	if (!path)
		error_exit("Usage: ./fdf <map.fdf>", 1);
}

void	init_data(t_data **env, char *path)
{
	check_path(path);
}

int main(int argc, char **argv)
{
	t_data	*env;

	init_data(&env, argv[1]);
	ft_printf("NOTHING THERE YET\n");
}