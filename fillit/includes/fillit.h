#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct			s_tminos
{
	char		order;
	int			x[4];
	int			y[4];
	struct s_tminos		*next;
}				t_tminos;

void			ft_play_the(t_tminos *game);
void			ft_minowriter(t_tminos **block, char *str);
void			ft_set_coord(t_tminos **piece, int x, int y);

char			**ft_fill_me(t_tminos *game, char **map, int s);
char			**ft_add_one(t_tminos *game, char **map, int s);
char			**ft_del_one(t_tminos *game, char **map, int s);
char			*ft_copy_input(int fd);
char			**ft_mapcreator(int s);

int				ft_check_place(t_tminos *mino, char **map, int s);
int				ft_minocounter(char *str);

t_tminos	*ft_get_minos(char *str)

#endif
