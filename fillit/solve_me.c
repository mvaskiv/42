/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <vblokha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:28:05 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/30 19:00:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char			**ft_fill_me(t_tminos *game, char **map, int s)
{
	int		x;
	int		y;
	char	**filled;

	x = 0;
	filled = NULL;
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
			if (filled)
				return (filled);
			map = ft_del_one(game, map, s);
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

void			ft_play_the(t_tminos *game, char *str)
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
