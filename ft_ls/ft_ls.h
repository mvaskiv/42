
#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>

typedef struct 		s_flags
{
	int 			a;
	int 			l;
	int 			R;
	int 			r;
	int			 	t;
}					t_flags;

typedef struct		s_output
{
	int 			word_count;
	int 			min_width;
	int 			true_width;
	int		 		columns;
	int				rows;
	int 			order;
	int 			words;
}					t_output;

typedef struct		s_files
{
	char 			*name;
	char 			*permissions;
	char 			*owner;
	char 			*year;
	char 			*size;
	char 			*date;
	int 			total;
	int 			row;
	struct s_files	*next;
}					t_files;

void		ft_ls_output(char *string, int win_width);

#endif