/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:46:56 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/17 18:32:10 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_height_and_width(t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(game->map_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
		{
			ft_putstr("Error---\n");
			free_all(game);
		}
		game->map_width = ft_strlen_to_n(line);
		free(line);
		i++;
	}
	game->map_height = i;
	close(fd);
}

char	**copy_map(char **map)
{
	char **copy;
	int y;
	int x_len;

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