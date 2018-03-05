/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:24:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/02/15 17:24:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_ls_core(t_flags *flag, DIR *dir, int winsize, char *path)
{
	t_files			*files;

	files = (t_files*)malloc(sizeof(t_files));
	files->data = (t_data*)malloc(sizeof(t_data));
//	files->data->name = NULL;
	files->next = NULL;
	if (flag->r == 1)
		files->data->moddate = 9999999999;
	else
		files->data->moddate = 0;
	ft_write_names(&files, dir, *flag);
	ft_sort_list(&files, *flag);
	if (flag->folders-- > 1)
		ft_mini_printf("%s:\n", ((ft_strstr(path, getenv("PWD")) > 0 ? ft_strjoin(".", path + ft_strlen(getenv("PWD"))) : path)));
	if (flag->t == 1)
		ft_sort_bydate(&files, *flag);
	if (flag->l == 1)
		ft_ls_l_output(files, path);
	if ((flag->l != 1))
		ft_ls_output(files, (flag->one == 1 ? 0 : winsize));
	ft_mini_printf( ((flag->folders > 0 || flag->R == 1) ? "\n" : "%c"), '\0');
	if (flag->R == 1)
		ft_ls_do(files, flag, path, winsize);
	closedir(dir);
	ft_free_lst(&files);
}

int 		main(int argc, char **argv)
{
	struct winsize	win;
	t_flags			flags;
	DIR				*dir;
	int 			i;

	i = 1;
	ft_initialize(&flags);
	ft_scan_flags(&flags, argv, argc);

	flags.l = 1;
//	flags.R = 1;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	while ((i < argc) && (argv[i][0] == '-'))
		i++;
	if (argv[i] && argv[i][0] != '-')
	{
		ft_count_folders(argv, i, &flags);
		while (argv[i] && (argv[i][0] != '-') && (dir = opendir(argv[i])))
			ft_ls_core(&flags, dir, win.ws_col, argv[i++]);
	}
	else
		ft_ls_core(&flags, opendir("/"), win.ws_col, "/");
	sleep (10);
	return (0);
}