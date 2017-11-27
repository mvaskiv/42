#include "libft.h"
#include "fillit.h"

void		ft_play_the(t_tminos *game)
{
	char		**filled;
	char		**map;
	int			i;

	i = 4;
	map = ft_mapcreator(i);
	while (!(filled = ft_fill_me(game, map, i)))
	{
		ft_memdel((void **)map);
		map = ft_mapcreator(i++);
	}
	ft_map_output(filled);
}

char		**ft_fill_me(t_tminos *game, char **map, int s)
{
	int		x;
	int		y;
	char	**filled;

	y = 0;
	if (game->next == NULL)
		return (map);
	while (y < s)
	{
		x = 0;
		while (x < s)
		{
			ft_set_coord(&game, x, y);
			if (ft_check_place(game, map, s))
				filled = ft_fill_me(ft_add_one(game, map, s), game->next, s);
			if(filled)
				return (filled);
			map = ft_del_one(map, game, s);
			x++;
		}
		y++;
	}
	return (NULL);
}
