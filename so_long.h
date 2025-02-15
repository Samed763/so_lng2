#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_controls
{
	int			fill_collectible_count;
	int			fill_exit_count;
	int			is_rectangular;
	int			is_closed;
	int			any_other_char;

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
	int			collectibles_count;
	int			player_count;
	int			exit_count;
	char		*map_name;
	char		**map;
	char		**visited;
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
void			find_thing_call(t_game *game);
void			read_xpm(t_game *game);
void			free_all(t_game *game);
void			check_map(t_game *game);
void			free_textures(t_game *game);
void			find_thing(t_game *game, char thing, char flag);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			free_map(char **map);
void			write_map(char **map, int height, int width);

int				check_file(t_game game);
int				ft_strlen_to_n(char *str);
int				fill_flood_check(char **map, int y, int x, char **visited);
int				check_chars(char *s, int c);

char			*ft_strcpy(char *str1, char *str2);

char			**copy_map(char **map);

#endif