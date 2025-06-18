/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:48:33 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 11:48:51 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data **env)
{
	if ((*env)->map)
		free_split((*env)->map);
	if ((*env)->win)
		mlx_destroy_window((*env)->mlx, (*env)->win);
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if (*env)
		free(*env);
	exit(0);
}
