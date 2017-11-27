#include "libft.h"
#include "fillit.h"

char		**ft_fill_me(t_tminos *game, char **map, int s)
{
	int		x;
	int		y;
	char	**filled;
	char **tmp;
	int i;

	x = 0;
	filled = NULL;
	if (game->next == NULL)
		return (map);
	tmp = map;
	while (x < s)
	{
		y = 0;
		while (y < s)
		{
			ft_set_coord(&game, x, y);
			if (ft_check_place(game, tmp, s))
			{
				filled = ft_fill_me(game->next, ft_add_one(game, tmp, s), s);
				i = 0;
				while (tmp[i])
					ft_putendl(tmp[i++]);
				ft_putendl("-------");
			}
			if (filled)
				return (filled);
			tmp = ft_del_one(game, tmp, s);
			y++;
		}
		x++;
	}
	return (NULL);
}

static int		ft_sqrt(int i)
{
	int q;

	q = 1;
	while ((q * q) < i)
		q++;
	return (q);
}

void		ft_play_the(t_tminos *game, char *str)
{
	char		**filled;
	char		**map;
	int			i;
	
	i = ft_sqrt(ft_minocounter(str) * 4);
	map = NULL;
	map = ft_mapcreator(map, i);
	while (!(filled = ft_fill_me(game, map, i)))
	{
		ft_memdel((void **)map);
		map = ft_mapcreator(map, ++i);
	}
	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}
