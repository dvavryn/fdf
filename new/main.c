#include "fdf.h"

typedef struct s_map
{
	int **map;
	size_t	i;
	size_t	j;
}	t_map;

void	ft_exit(char *msg, int status)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	if (status)
		exit(status);
}

void	check_path(char *path)
{
	ssize_t	i;

	i = -1;
	while (path[++i])
		;
	if (ft_strcmp(&path[i - 4], ".fdf"))
		ft_exit("Wrong file specificer!\n", 1);
}

char *readin(int fd)
{
	char *out;
	char *tmp;
	ssize_t	b;
	char buf[10];

	b = 1;
	out =ft_strdup("");
	if (!out)
		return (NULL);
	while (b > 0)
	{
		ft_bzero(buf, sizeof(buf));
		b = read(fd, buf, sizeof(buf) - 1);
		if (b < 0)
			return (free(out), NULL);
		tmp = out;
		out = ft_strjoin(out, buf);
		free(tmp);
		if (!out)
			return (NULL);
	}
	close(fd);
	return (out);
}

char *get_oneline(char *path)
{
	int fd;
	char *out;
	ssize_t	i;

	check_path(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	out = readin(fd);
	if (!out)
		return (NULL);
	i = -1;
	while (out[++i])
	{
		if (!(ft_isspace(out[i]) || ft_isdigit(out[i]) || out[i] == '\n'
			|| out[i] == '-' || out[i] == '+'))
			return (free(out), NULL);
	}
	return (out);
}

void	get_map_size(char *oneline, size_t *i, size_t *j)
{
	ssize_t	x;
	size_t	buf;
	x = -1;
	*j = 0;
	*i = 0;
	buf = 0;
	while (oneline[++x])
	{
		if (ft_isdigit(oneline[x]) && (oneline[x + 1] == ' '  || !oneline[x + 1]))
		{
			*j += 1;
			if (!i)
			{
				buf = *j;
				ft_printf("%i - %i", *j, buf);
			}
		}
		if (oneline[x] == '\n')
		{
			// if (oneline[x + 1])
			// 	*j = 0;
			*i += 1;
		}
	}
	// if (buf != *j)
	// {
	// 	*i = 0;
	// 	*j = 0;
	// }
}

void	get_map_data(int **map, size_t *i, size_t *j, char *path)
{
	char *oneline;

	oneline = get_oneline(path);
	if (!oneline)
		ft_exit("get_oneline failed!\n", 1);
	get_map_size(oneline, i, j);
	ft_printf("%s\ni: %i\nj: %i\n", oneline, *i, *j);
	free(oneline);
}

int main(int argc, char **argv)
{
	t_map	map;

	get_map_data(map.map, &map.i, &map.j, argv[1]);
	if (!map.map)
		return(1);
	
}