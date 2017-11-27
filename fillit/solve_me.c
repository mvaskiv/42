#include "libft.h"
#include "fillit.h"

char		**ft_fill_me(t_tminos *game, char **map, int s)
{
	int		x;
	int		y;
	char	**filled;

	x = 0;
	if (game->next == NULL)
		return (map);
	while (x < s)
	{
		y = 0;
		while (y < s)
		{
			ft_set_coord(&game, x, y);
			if (ft_check_place(game, map, s))
				filled = ft_fill_me(game->next, ft_add_one(game, map, s), s);
			if(filled)
				return (filled);
			map = ft_del_one(game, map, s);
			y++;
		}
		x++;
	}
	return (NULL);
}

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
		map = ft_mapcreator(++i);
	}
	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}
