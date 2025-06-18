#include "fdf.h"



int main(int argc, char **argv)
{
	t_data	*env;

	init_data(&env, argv[1]);

	for(int i = 0; env->map[i]; i++)
	{
		ft_printf("%s\n", env->map[i]);
	}
}