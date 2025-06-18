#include "fdf.h"

void	init_data(t_data **env, char *path)
{
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit(70);
	get_map(env, path);
}