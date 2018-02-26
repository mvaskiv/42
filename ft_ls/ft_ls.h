
#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct 		s_flags
{
	int 			one; //
	int 			a; //done
	int 			l; //done
	int 			R;
	int 			r; //done
	int			 	t; //done
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
	struct stat		stats;
	struct tm		*time;
	struct group	*grp;
	__darwin_time_t moddate;
	struct s_files	*next;
}					t_files;

void 		ft_ls_core(t_flags flag, DIR *dir);

void 		ft_scan_flags(t_flags *flags, char **arg, int argc);

void		ft_write_names(t_files **files, DIR *dir, t_flags flag);
void		ft_sort_bydate(t_files **files, t_flags flag);
void		ft_sort_list(t_files **files, t_flags flag);
void		ft_write_stats(t_files **files);

void		ft_ls_l_output(t_files *files);
void		ft_ls_output(char *string, int win_width);
void		ft_read_list(t_files *files);


#endif