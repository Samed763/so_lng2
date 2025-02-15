/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:10:46 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/15 17:34:22 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_controls(t_game *game)
{
	game->controls.fill_collectible_count = 0;
	game->controls.fill_exit_count = 0;
	game->controls.is_rectangular = 0;
	game->controls.is_closed = 0;
	game->controls.any_other_char = 0;
	
}

static void	initialize_textures(t_game *game)
{
	game->textures.width = 0;
	game->textures.height = 0;
}

static void	initialize_player(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.steps = 0;
}
void	read_xpm(t_game *game)
{
	ft_putstr("read_xpm\n");
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/bricks.xpm", &game->textures.width,
			&game->textures.height);
	ft_putstr("read_xpm\n");
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/leavesop.xpm", &game->textures.width,
			&game->textures.height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/bookshelf.xpm", &game->textures.width,
			&game->textures.height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/gemov2.xpm", &game->textures.width,
			&game->textures.height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"textures/gold1.xpm", &game->textures.width,
			&game->textures.height);
}
void	initialize_game(t_game *game)
{
	ft_putstr("initialize_game\n");
	game->map_width = 0;
	game->map_height = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->th_x = 0;
	game->th_y = 0;
	game->collectibles_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->map = NULL;
	game->visited = NULL;
	initialize_controls(game);
	initialize_textures(game);
	initialize_player(game);
	read_xpm(game);
}
