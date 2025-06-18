/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:38:29 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 12:11:11 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define WID 400
# define HEI 400

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
	char	**map;
	void	*mlx;
	void	*win;
}	t_data;

// ------------------------
void	get_map(t_data **env, char *path);
void	error_exit(char *msg, int status);
void	init_data(t_data **env, char *path);
void	free_data(t_data **env);

// Felt cute today may delete later!
void	my_pixel_put(t_img *img, int x, int y, int color);
void	my_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);

#endif