#include "so_long.h"

int	check_chars(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_file(t_game game)
{
    int		i;
    int		j;
    char	ext[5] = ".ber";
    
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
    return (1);
}
