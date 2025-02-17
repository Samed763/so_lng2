/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:04:11 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/16 17:46:55 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_file(t_game game)
{
	int		i;
	int		j;
	int		fd;
	char	ext[5] = ".ber";

	fd = open(game.map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	j = 0;
	if (!game.map_name || ft_strlen(game.map_name) < 4)
		return (0);
	i = ft_strlen(game.map_name) - 1;
	while (j < 4)
	{
		if (game.map_name[i] != ext[3 - j])
			return (0);
		i--;
		j++;
	}
	close(fd);
	return (1);
}
void	read_map_lines(t_game *game, int fd)
{
    int	j;
    int	line_len;

    j = 0;
    while (j < game->map_height)
    {
        game->map[j] = get_next_line(fd);
        line_len = ft_strlen_to_n(game->map[j]);
        if (line_len != game->map_width)
        {
            free(game->map[j]);
            game->map = NULL;
            return ;
        }
        j++;
    }
    game->map[game->map_height] = NULL;
}

void	read_map(t_game *game)
{
    int	fd;

    set_height_and_width(game);
    fd = open(game->map_name, O_RDONLY);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!game->map)
    {
        game->map = NULL;
        return ;
    }
    read_map_lines(game, fd);
    close(fd);
}



void	render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_wall(game, x, y);
			else if (game->map[y][x] == '0')
				put_floor(game, x, y);
			else if (game->map[y][x] == 'P')
				put_player(game, x, y);
			else if (game->map[y][x] == 'E')
				put_exit(game, x, y);
			else if (game->map[y][x] == 'C')
				put_collectible(game, x, y);
			x++;
		}
		y++;
	}
}