/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:39:26 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 11:49:26 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_data **env, char *path)
{
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit(70);
	get_map(env, path);
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
		free_data(env);
	(*env)->win = mlx_new_window((*env)->mlx, 400, 400, "fdf");
	if (!(*env)->win)
		free_data(env);
}
