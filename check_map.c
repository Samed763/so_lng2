/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:32:54 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/17 17:54:30 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_shape(t_game *game)
{
	if (game->map_width == game->map_height)
	{
		game->controls.is_rectangular = 1;
	}
}

static void	check_top_bottom(t_game *game)
{
	int	x;

	x = 0;
	while (x < ft_strlen_to_n(game->map[0]))
	{
		if (game->map[0][x] != '1')
		{
			game->controls.is_closed = 1;
		}
		x++;
	}
	x = 0;
	while (x < ft_strlen_to_n(game->map[game->map_height - 1]))
	{
		if (game->map[game->map_height - 1][x] != '1')
		{
			game->controls.is_closed = 1;
		}
		x++;
	}
}

static void	check_left_right(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
		{
			game->controls.is_closed = 1;
		}
		y++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][game->map_width - 1] != '1')
		{
			game->controls.is_closed = 1;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	map_shape(game);
	check_left_right(game);
	check_top_bottom(game);
	if (game->controls.fill_collectible_count > 0 || game->player_count != 1
		|| game->exit_count != 1 || game->controls.is_rectangular == 1
		|| game->controls.is_closed == 1 || game->collectibles_count <= 0
		|| game->controls.fill_exit_count == 1)
	{
		ft_putstr("Error\n");
		free_all(game);
	}
}
