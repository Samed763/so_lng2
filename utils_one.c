#include "so_long.h"

void set_height_and_width(t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_width = ft_strlen_to_n(line);
		free(line);
		i++;
	}
	game->map_height = i;
	close(fd);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		y;
	int		x_len;

	y = 0;
	x_len = 0;
	while (map[y])
		y++;
	copy = malloc(sizeof(char *) * (y + 1));
	x_len = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		copy[y] = malloc(sizeof(char) * (x_len + 1));
		ft_strcpy(copy[y], map[y]);
		copy[y][x_len] = '\0';
		y++;
	}
	copy[y] = NULL;
	return (copy);
}