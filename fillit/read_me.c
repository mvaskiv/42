#include "libft.h"
#include "fillit.h"

char		*ft_copy_input(int fd)
{
	int	i;
	int	fdd;
	char	c;
	char	*str;

	i = 0;
	fdd = read(fd, &c, 1);
	if (fdd != 1)
		return(NULL);
	else
	{
		if(!(str = (char *)malloc(sizeof(char) * 546)))
		 	return (NULL);
		while (fdd != '\0')
		{
			str[i++] = c;
			fdd = read(fd, &c, 1);
		}
		while (str[i])
			str[i++] = '\0';
	}
	return (str);
}

t_tminos	*ft_get_minos(char *str)
{
	int		i;
	int		q;
	char		letter;
	t_tminos	*input;
	t_tminos	*tmp;

	i = 0;
	letter = 65;
	q = ft_minocounter(str);
	if (!(input = (t_tminos *)malloc(sizeof(t_tminos))))
		return (NULL);
	tmp = input;
	while (q > 0)
	{
		tmp->order = letter;
		ft_minowriter(&tmp, ft_strsub(str, i, 20));
		if (!(tmp->next = (t_tminos *)malloc(sizeof(t_tminos))))
			return (NULL);
		tmp = tmp->next;
		letter++;
		i += 21;
		q--;
	}
	tmp->next = NULL;
	return (input);
}

char		**ft_add_one(t_tminos *game, char **map, int s)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	while (x < s)
	{
		y = 0;
		while (y < s)
		{
			if (game->x[i] == x && game->y[i] == y)
			{
				map[x][y] = game->order;
				i++;
			}
			y++;
		}
		x++;
	}
	return (map);
}

char		**ft_del_one(t_tminos *game, char **map, int s)
{
	int		x;
	int		y;

	x = 0;
	while (x < s)
	{
		y = 0;
		while (y < s)
		{
			if (map[x][y] == game->order)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}
