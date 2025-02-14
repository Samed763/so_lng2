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