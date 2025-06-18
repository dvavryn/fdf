#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "../libft/libft.h"
#include <fcntl.h>

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
}	t_data;

// ------------------------
void	get_map(t_data **env, char *path);
void	error_exit(char *msg, int status);
void	init_data(t_data **env, char *path);

#endif