#include "so_long.h"

static void	print_all(t_game *game)
{
	printf("game->map_name: %s\n", game->map_name);
	printf("game->map_width:%d game->map_height:%d \n\n", game->map_width,
		game->map_height);
	printf("game->exit_x:%d game->exit_y:%d \n\n", game->exit_x, game->exit_y);
	printf("game->player.x:%d game->player.y:%d \n\n", game->player.x,
		game->player.y);
	printf("game->collectibles_count:%d game->player_count:%d \n\n",
		game->collectibles_count, game->player_count);
	printf("game->exit_count:%d \n\n", game->exit_count);
	printf("game->controls.fill_collectible_count:%d\n",
		game->controls.fill_collectible_count);
	printf("game->controls.fill_exit_count:%d\n",
		game->controls.fill_exit_count);
	printf("game->controls.is_rectangular:%d\n", game->controls.is_rectangular);
	printf("game->controls.is_closed:%d\n", game->controls.is_closed);
	printf("game->controls.any_other_char:%d\n", game->controls.any_other_char);
}

int	fill_flood_check(char **map, int y, int x, char **visited)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || visited[y][x] == '1'
		|| map[y][x] == '1')
		return (0);
	visited[y][x] = '1';
	fill_flood_check(map, y - 1, x, visited);
	fill_flood_check(map, y + 1, x, visited);
	fill_flood_check(map, y, x - 1, visited);
	fill_flood_check(map, y, x + 1, visited);
	return (1);
}

void	read_map(t_game *game) // returna gerek yok
{
	int j;
	int fd;
	int line_len;

	set_height_and_width(game);
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
	// 1. Read the map
	ft_putstr("read_map\n");
	read_map(game);
	if (!game->map)
	{
		printf("Error\n");
		return ;
	}
	find_thing_call(game);
	write_map(game->map, game->map_height, game->map_width);
	print_all(game);
	// 2. Validate the map
	check_map(game);
	
}

int	main(int argc, char *argv[])
{
	t_game	game;

	game.map_name = argv[1];
	if (argc != 2 || !check_file(game))
	{
		printf("Error\n argc control");
		return (1);
	}
	game.mlx = mlx_init();
	to_do_list(&game);
}
