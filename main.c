/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:47:07 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/17 15:48:19 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	move_character(t_game *game, int way_x, int way_y)
{
	game->player.new_x = game->player.x + way_x;
	game->player.new_y = game->player.y + way_y;
	if (game->map[game->player.new_y][game->player.new_x] != '1')
	{
		game->player.steps++;
		ft_putstr("Player step count:");
		ft_putnbr(game->player.steps);
		ft_putchar('\n');
	}
	if (game->map[game->player.new_y][game->player.new_x] == 'C'
		|| game->map[game->player.new_y][game->player.new_x] == '1'
		|| game->map[game->player.new_y][game->player.new_x] != 'E')
		to_others(game);
	else
		to_floor(game);
	game->map[game->exit_y][game->exit_x] = 'E';
}

static void	to_do_list(t_game *game)
{
	initialize_game(game);
	read_map(game);
	if (!game->map)
	{
		printf("Error\n");
		free_all(game);
		return ;
	}
	find_thing_call(game);
	write_map(game->map, game->map_height, game->map_width);
	check_map(game);
}
static int	handle_key(int key, t_game *game)
{
	if (key == 65307)
		free_all(game);
	else if (key == 'w' || key == 'W')
		move_character(game, 0, -1);
	else if (key == 'a' || key == 'A')
		move_character(game, -1, 0);
	else if (key == 's' || key == 'S')
		move_character(game, 0, 1);
	else if (key == 'd' || key == 'D')
		move_character(game, 1, 0);
	return (0);
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
	game.win = mlx_new_window(game.mlx, game.map_width * 64, game.map_height
			* 64, "so_long");
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, free_all, &game);
	mlx_loop(game.mlx);
}
