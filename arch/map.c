/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:33:00 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/18 11:42:14 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	check_file_specifier(char *path)
{
	size_t	i;

	i = 0;
	while (path[i])
		i++;
	i -= 4;
	if (ft_strcmp(".fdf", &path[i]))
		return (0);
	return (1);
}

void	check_path(char *path)
{
	if (!check_file_specifier(path))
		error_exit("Wrong file type", 2);
}

void	get_map(t_data **env, char *path)
{
	int		fd;
	ssize_t	b;
	char	s[10];
	char	*out;
	char	*tmp;

	check_path(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("Could not open file", 3);
	b = 1;
	out = ft_strdup("");
	if (!out)
		exit(100);
	ft_bzero(s, 10);
	while (b > 0)
	{
		b = read(fd, s, 9);
		if (b == -1)
			exit(101);
		tmp = out;
		out = ft_strjoin(out, s);
		free(tmp);
		if (!out)
			exit(102);
		ft_bzero(s, 10);
	}
	(*env)->map = ft_split(out, '\n');
	free(out);
	if (!(*env)->map)
		exit(103);
}
