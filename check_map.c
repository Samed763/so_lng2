/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:32:54 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/15 18:14:45 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	map_shape(t_game *game)
{
	if (game->map_width == game->map_height)
	{
		ft_putstr("Error\n");
		game->controls.is_rectangular = 1;
	}
}

static void	check_top_bottom(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1')
		{
			ft_putstr("Error\n");
			game->controls.is_closed = 1;
		}
		x++;
	}
	x = 0;
	while (x < game->map_width)
	{
		if (game->map[game->map_height - 1][x] != '1')
		{
			ft_putstr("Error\n");
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
			ft_putstr("Error\n");
			game->controls.is_closed = 1;
		}
		y++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][game->map_width - 1] != '1')
		{
			ft_putstr("Error\n");
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
	if (game->collectibles_count <= 0 || game->player_count != 1
		|| game->exit_count != 1 || game->controls.is_rectangular == 1
		|| game->controls.is_closed == 1)
	{
		ft_putstr("Errorzzz\n");
		free_all(game);
	}
}
