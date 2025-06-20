#include "../libft/libft.h"
#include <fcntl.h>

char *get_oneline(char *path)
{
    char *out;
    ssize_t b;
    char s[10];
    char *tmp;
    int fd;

    fd = open(path, O_RDONLY);
    out = ft_strdup("");
    if (fd < 0 || !out)
        return (NULL);
    b = 1;
    while (b > 0)
    {
        ft_bzero(s, 10);
        b = read(fd, s, 9);
        if (b == -1)
            return (NULL);
        tmp = out;
        out = ft_strjoin(out, s);
        free(tmp);
        if (!out)
            return (NULL);
    }
    return (out);
}

char **get_map(char *path)
{
    char **out;
    char *oneline;

    oneline = get_oneline(path);
    if (!oneline)
        return (NULL);
    out = ft_split(oneline, '\n');
    if (!out)
        return (NULL);

    return (out);
}

int main(void)
{
    char **map = get_map("maps/42.fdf");
    if (!map)
        return 4;
    for(int i = 0; map[i]; i++)
    {
        ft_printf("%s\n", map[i]);
    }
}