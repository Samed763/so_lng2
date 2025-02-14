#include "so_long.h"


void	free_map(char **map)
{
    int i;

    if (map)
    {
        i = 0;
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

void	read_map(t_game *game) // returna gerek yok
{
	int j;
	int fd;
	int line_len;

	j = 0;
	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
		game->map = NULL;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		game->map = NULL;
	while (j < game->map_height)
	{
		game->map[j] = get_next_line(fd);
		line_len = ft_strlen_to_n(game->map[j]);
		if (line_len != game->map_width)
			game->map = NULL;
		j++;
	}
	game->map[game->map_height] = NULL;
	close(fd);
}

void	to_do_list(t_game *game)
{
	// 0. Initialize the game
	initialize_game(game);
	printf("game->map_name: %s\n", game->map_name);
	
	printf("game->map_width:%d game->map_height:%d \n\n", game->map_width,
		game->map_height);
	// 1. Read the map
	read_map(game);
    if (!game->map)
    {
        printf("Error\n");
        return ;
    }
	// 2. Validate the map
	// 3. Load the textures
	// 4. Initialize the game
	// 5. Start the game loop
	write_map(game->map, game->map_height, game->map_width);
    free_map(game->map);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\n argc control");
		return (1);
	}
	game.map_name = argv[1];
	to_do_list(&game);
}
