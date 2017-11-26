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

char				*ft_copy_input(int fd);

#endif
