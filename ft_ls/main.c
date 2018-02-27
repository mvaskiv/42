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

void		ft_sort_bydate(t_files **files, t_flags flag)
{
	t_files		*temp;
	char 		*swap = NULL;
	t_files		**start;
	__darwin_time_t time_swap;

	start = files;
	temp = *files;
	while (temp->next)
	{
		if ((flag.r == 0 ? (temp->moddate < temp->next->moddate) :
					(temp->moddate > temp->next->moddate)))
		{
			swap = temp->name;
			time_swap = temp->moddate;
			temp->name = temp->next->name;
			temp->moddate = temp->next->moddate;
			temp->next->name = swap;
			temp->next->moddate = time_swap;
			ft_sort_bydate(start, flag);
		}
		temp = temp->next;
	}
}

void		ft_sort_list(t_files **files, t_flags flag)
{
	t_files		*temp;
	__darwin_time_t time_swap;
	char		*swap = NULL;
	t_files		**start;

	start = files;
	temp = *files;
	while (temp->next)
	{
		if ((flag.r == 0 ? (ft_strcmp(temp->name, temp->next->name) > 0) :
			 (ft_strcmp(temp->name, temp->next->name) < 0)))
		{
			swap = temp->name;
			time_swap = temp->moddate;
			temp->name = temp->next->name;
			temp->moddate = temp->next->moddate;
			temp->next->name = swap;
			temp->next->moddate = time_swap;
			ft_sort_list(start, flag);
		}
		temp = temp->next;
	}
}

void		ft_write_names(t_files **files, DIR *dir, t_flags flag)
{
	t_files			*temp;
	t_files			**start;
	struct dirent	*directory;

	while ((directory = readdir(dir)))
	{
		start = files;
		temp = *files;
		temp = (t_files *) malloc(sizeof(t_files));
		while (flag.a != 1 && (char) directory->d_name[0] == '.')
			directory = readdir(dir);
		temp->name = ft_strdup(directory->d_name);
		lstat(directory->d_name, &temp->stats);
		temp->moddate = temp->stats.st_ctimespec.tv_sec; // or maybe st_mtimespec ???
		temp->namlen = directory->d_namlen;
		temp->grp = NULL;
		temp->next = *start;
		*files = temp;
		temp = *files;
	}
}

void		ft_initialize(t_flags *flags)
{
	flags->one = 0;
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->R = 0;
	flags->t = 0;
}

int 	main(int argc, char **argv)
{
	struct winsize	win;
	t_flags			flags;
	DIR				*dir;
	int 			i;

	i = 1;
	ft_initialize(&flags);
	ft_scan_flags(&flags, argv, argc);

	flags.l = 1;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	while ((i < argc) && (argv[i][0] == '-'))
		i++;
	if (argv[i] && argv[i][0] != '-')
		while (argv[i] && (argv[i][0] != '-') && (dir = opendir(argv[i])))
			ft_ls_core(flags, dir, win.ws_col, argv[i++]);
	else
		ft_ls_core(flags, opendir(getenv("PWD")), win.ws_col, getenv("PWD"));

//	ft_ls_output(string, w.ws_col > 0 ? w.ws_col : 1);
	return (0);
}