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
	t_files			*files = NULL;

	ft_write_n_sort(&files, dir, flag, path);
	if (flag->folders > 1)
		ft_mini_printf("%s:\n", ((ft_strstr(path, getenv("PWD")) > 0 ? ft_strjoin(".", path + ft_strlen(getenv("PWD"))) : path)));
	if (flag->l == 1)
		ft_ls_l_output(files, path);
	if ((flag->l != 1))
		ft_ls_output(flag, files, (flag->one == 1 ? 0 : winsize));
//	ft_mini_printf( ((flag->folders > 0) ? "\n" : "%c"), '\0');
	if (flag->R == 1)
		ft_ls_do(files, flag, path, winsize);
	closedir(dir);
	ft_free_lst(&files);
}

int 		main(int argc, char **argv)
{
	struct winsize	win;
	t_flags			flags;
	DIR				*dir = NULL;
	int 			i;

	i = 1;
	ft_initialize(&flags);
	if (!(ft_scan_flags(&flags, argv, argc)))
		return (1);

//	flags.l = 1;
//	flags.r = 0;
//	flags.a = 1;
//	flags.R = 1;
//	flags.t = 1;
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
//	sleep (10);
	return (0);
}