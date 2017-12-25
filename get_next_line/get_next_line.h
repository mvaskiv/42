#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct		s_line
{
	void									*content;
	unsigned int					file;
	struct s_line					*next;
}									t_line;

int		get_next_line(const int fd, char **line);

#endif
