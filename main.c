/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:38:12 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 11:49:40 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	*env;

	if (argc != 2)
		error_exit("Usage: ./fdf <map.fdf>", 1);
	init_data(&env, argv[1]);

	for(int i = 0; env->map[i]; i++)
	{
		ft_printf("%s\n", env->map[i]);
	}
	free_data(&env);
}
