#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_controls
{
	int			collectibles_count;
	int 		player_count;
	int			exit_count;
	int			is_rectangular;
	int			is_closed;
	int			any_other_char;
	int			valid_path;
}				t_controls;

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*collectible;
	void		*exit;
	void		*player;
	int			width;
	int			height;
}				t_textures;

typedef struct s_player
{
	int			x;
	int			y;
	int			steps;
}				t_player;

typedef struct g_game
{
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	int			exit_x;
	int			exit_y;
	int			th_x;
	int			th_y;
	char		*map_name;
	char		**map;
	t_player	player;
	t_controls	controls;
	t_textures	textures;
}				t_game;

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void			initialize_game(t_game *game);
void			set_height_and_width(t_game *game);
void			write_map(char **map, int height, int width);

void			ft_putchar(char c);
void			ft_pustr(char *str);
void			ft_putnbr(int n);

int				ft_strlen_to_n(char *str);

#endif