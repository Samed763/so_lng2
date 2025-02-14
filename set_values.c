/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:10:46 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/14 18:25:14 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_controls(t_game *game)
{
    game->controls.collectibles_count = 0;
    game->controls.exit_count = 0;
    game->controls.is_rectangular = 1;
    game->controls.is_closed = 1;
    game->controls.any_other_char = 0;
    game->controls.valid_path = 1;
}

static void	initialize_textures(t_game *game)
{
    game->textures.wall = NULL;
    game->textures.floor = NULL;
    game->textures.collectible = NULL;
    game->textures.exit = NULL;
    game->textures.player = NULL;
    game->textures.width = 0;
    game->textures.height = 0;
}

static void	initialize_player(t_game *game)
{
	game->player.x = 0;
    game->player.y = 0;
    game->player.steps = 0;
}

void	initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->map = NULL;
	initialize_controls(game);
	initialize_textures(game);
	initialize_player(game);
    set_height_and_width(game);
}
