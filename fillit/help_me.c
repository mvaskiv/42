#include "libft.h"
#include "fillit.h"

int		ft_minocounter(char *str)
{
	int		i;
	int		q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == '#')
			q++;
		i++;
	}
	return (q / 4);
}

void		ft_minowriter(t_tminos **block, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*block)->x[j] = i % 5;
			(*block)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

char		**ft_mapcreator(int s)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	if (!(map = (char **)malloc(sizeof(char *) * s + 1)))
		return (NULL);
	while (x < s)
	{
		if (!(map[x] = (char *)malloc(sizeof(char) * s + 1)))
			return (NULL);
		y = 0;
		while (y < s)
			map[x][y++] = '.';
		map[x][y] = '\0';
		x++;
	}
	map[x] = '\0';
	return (map);
}

void		ft_set_coord(t_tminos **piece, int x, int y)
{
	int		i;
	int		max_x;
	int		max_y;

	i = 0;
	max_x = 100;
	max_y = 100;
	while (i < 4)
	{
		if ((*piece)->x[i] < max_x)
			max_x = (*piece)->x[i];
		if ((*piece)->y[i] < max_y)
			max_y = (*piece)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*piece)->x[i] = (*piece)->x[i] - max_x + x;
		(*piece)->y[i] = (*piece)->y[i] - max_y + y;
		i--;
	}
}
