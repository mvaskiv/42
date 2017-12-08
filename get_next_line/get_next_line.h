#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

typedef struct		s_line
{
	char						*string[BUFF_SIZE];
	struct s_line					*next;
}									t_line;

int		get_next_line(const int fd, char **line);

#endif
