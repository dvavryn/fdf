#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int **get_map()
{
	char *oneline = \
	"+0  0  -0  0\n0  0a  0  0\n0  0  0  0\n0  0  0  0";

	if (check_valid(oneline))
		return (free(oneline), NULL);
	
	printf("hello");
	return (NULL);
}

int main(void)
{
	int	**map = get_map();
}