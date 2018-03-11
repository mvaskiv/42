/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:33:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 17:50:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_data
{
	int				namlen;
	mode_t			mode;
	gid_t			group;
	nlink_t			link;
	dev_t			dev;
	uid_t			user;
	time_t			time;
	off_t			size;
	blkcnt_t		blocks;
	long int		moddate;
}					t_data;

typedef struct		s_files
{
	char			*name;
	char			*path;
	struct s_data	*data;
	struct s_files	*next;
}					t_files;

typedef struct		s_flags
{
	int				one;
	int				a;
	int				l;
	int				rh;
	int				r;
	int				t;
	int				folders;
}					t_flags;

typedef struct		s_output
{
	int				word_count;
	int				min_width;
	int				true_width;
	int				columns;
	int				rows;
	int				order;
	int				words;
}					t_output;

typedef struct		s_l_out
{
	int				n_sl;
	int				n_us;
	int				n_gr;
	int				n_sz;
	int				blocks;
}					t_l_out;

void				ft_ls_core(t_flags *flag, DIR *dir,
	int winsize, char *path);
void				ft_ls_do(t_files *the, t_flags *magic, int fucker);
void				ft_ls_output(t_files *files, t_flags *flag, int win_width);
void				ft_ls_l_output(t_files *temp, char *path);

void				ft_read_list(t_files *files, t_l_out width);
int					ft_scan_flags(t_flags *flags, char **arg, int argc);
void				ft_write_names(t_files **files, DIR *dir,
	t_flags flag, char *path);
void				ft_sort_bydate(t_files **files, t_flags flag);
void				ft_sort_list(t_files **files, t_flags flag);
void				ft_write_stats(t_files **files, char *path_a);

void				ft_read_ext_perm(char *path);
void				ft_read_link(t_files *files);

void				ft_set_cols(t_files *files, t_l_out *width);
void				ft_print_type(t_files *files);
void				ft_sticky_bit(t_files *files);

void				ft_initialize(t_flags *flags);
int					ft_count_folders(char **argv, int i,
	int argc, char **files);
void				ft_free_lst(t_files **files);
void				ft_set_stock(t_output *stock, t_files *files,
	int win_width);

char				*ft_get_path(char *name, char *path);

char				*ft_alter_path(char **path, char *name);
char				*ft_get_uname(uid_t uid);
char				*ft_month(int month_n);
int					ft_true_width(int min_width);
int					ft_columns_number(int word_count, int min_width,
	int win_width);
int					ft_high_namlen(t_files *files, int type);
int					ft_flag_error(char *arg);

void				ft_insert_file(t_files **files, t_files *new,
	t_flags *flag);
void				ft_write_n_sort(t_files **files, DIR *dir,
	t_flags *flag, char *path);
void				ft_write_l_stats(t_files **files, char *path_a);
void				ft_l_link(char *path);

t_files				*ft_new_node(struct dirent *directory, char *path);

#endif
