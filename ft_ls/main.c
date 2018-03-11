/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:24:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 18:29:58 by mvaskiv          ###   ########.fr       */
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
		ft_ls_output(files, (flag->one == 1 ? 0 : winsize));
	if (flag->rh == 1)
		ft_ls_do(files, flag, winsize);
	if (flag->folders > 1 && flag->rh != 1 && files != NULL)
		ft_putchar('\n');
	closedir(dir);
	ft_free_lst(&files);
}

int			ft_check_folders(int argc, char **argv, int i, int win)
{
	t_flags		flags;
	DIR			*dir;
	int			f;
	char		**files;

	f = 0;
	ft_initialize(&flags);
	if (!(ft_scan_flags(&flags, argv, argc)))
		return (1);
	files = (char**)malloc(sizeof(char) * argc);
	flags.folders = ft_count_folders(argv, i, argc, files);
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
	return (0);
}

int			main(int argc, char **argv)
{
	struct winsize	win;
	t_flags			flags;
	int				i;

	i = 1;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	while ((i < argc) && (argv[i][0] == '-'))
		i++;
	if (argv[i] && argv[i][0] != '-')
	{
		return ((ft_check_folders(argc, argv, i, win.ws_col)) ? 1 : 0);
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
