#include "so_long.h"

void	write_map(char **map, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ft_putchar(map[i][j]);
		}
		printf("\n");
	}
}