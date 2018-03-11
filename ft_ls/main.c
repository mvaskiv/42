/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:24:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 17:41:42 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_core(t_flags *flag, DIR *dir, int winsize, char *path)
{
	t_files		*files;

	ft_write_n_sort(&files, dir, flag, path);
	if (flag->folders > 1)
		ft_mini_printf("%s:\n", ((ft_strstr(path, getenv("PWD")) > 0 ?
			ft_strjoin(".", path + ft_strlen(getenv("PWD"))) : path)));
	if (flag->l == 1)
		ft_ls_l_output(files, path);
	if ((flag->l != 1))
		ft_ls_output(files, flag, (flag->one == 1 ? 0 : winsize));
	if (flag->rh == 1)
		ft_ls_do(files, flag, winsize);
	closedir(dir);
	ft_free_lst(&files);
}

void		ft_check_folders(int argc, char **argv, int i, int win)
{
	t_flags		flags;
	DIR			*dir;
	int 		j;
	int 		f;
	char 		**files;

	j = i;
	f = 0;
	ft_initialize(&flags);
	files = (char**)malloc(sizeof(char) * argc);
	if (!(ft_scan_flags(&flags, argv, argc)))
		return ;
	ft_count_folders(argv, i, &flags, argc, files);
	if (files[0] != NULL)
	{
		while (files[f] != NULL)
			ft_putendl(files[f++]);
		ft_putchar('\n');
	}
	while (argv[i] && (argv[i][0] != '-') && i < argc)
	{
		if ((dir = opendir(argv[i])))
			ft_ls_core(&flags, dir, win, argv[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	struct winsize	win;
	t_flags			flags;
	DIR				*dir;
	int				i;

	i = 1;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	while ((i < argc) && (argv[i][0] == '-'))
		i++;
	if (argv[i] && argv[i][0] != '-')
	{
		ft_check_folders(argc, argv, i, win.ws_col);
	}
	else
	{
		ft_initialize(&flags);
		if (!(ft_scan_flags(&flags, argv, argc)))
			return (1);
		ft_ls_core(&flags, opendir(getenv("PWD")), win.ws_col, getenv("PWD"));
	}
	return (0);
}
