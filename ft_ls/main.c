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
#include <stdio.h>

char 	*ft_output_table(char *string, int win_width)
{
	char 	**arr;
	int 	i;
	int 	j;
	int		c;

	c = 0;
	j = 0;
	i = 0;
	arr = ft_strsplit(string, '\t');
	while (arr[j] != NULL)
	{
		if (ft_strlen(arr[j]) > i)
			i = ft_strlen(arr[j]);
		j++;
	}
	j = 0;
//	win_width = 82;
	c = win_width / i;
	c--;
	if (c < 0)
		c = 1;
	arr = ft_sorttab(arr);
	while (arr[j])
	{
		ft_mini_printf("%-*s\t", i , arr[j]);
		j++;
		if ((j % c) == 0)
			printf("\r\n");
	}
//	printf("\n");
	return (0);
}

void 	ft_scan_flags(t_flags *flags, char *arg)
{
	int 	i;

	i = 0;
	while (arg[i++])
	{
		flags->a = ft_strchr(arg, 'a') ? 1 : 0;
		flags->l = ft_strchr(arg, 'l') ? 1 : 0;
		flags->r = ft_strchr(arg, 'r') ? 1 : 0;
		flags->R = ft_strchr(arg, 'R') ? 1 : 0;
		flags->t = ft_strchr(arg, 't') ? 1 : 0;
	}
}

int 	main(int argc, char **argv)
{
	struct winsize	w;
	struct dirent	*directory;
	struct stat		stats;
	t_files			files;
	t_flags			flags;
	char 			*string = NULL;
	DIR				*dir;

	if (argc == 2 && argv[1][0] != '-')
		dir = opendir(argv[1]);
	else if (argc == 3 && argv[1][0] == '-')
		dir = opendir(argv[2]);
	else
		dir = opendir(getenv("PWD"));
	if (argc > 1 && argv[1][0] == '-')
		ft_scan_flags(&flags, argv[1]);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//	flags.l = 1;
	while ((directory = readdir(dir)))
	{
//		if (flags.l == 1)
//		{
//			stat(directory->d_name, &stats);
//			printf("%d %d %d\n", stats.st_mode, stats.st_uid, stats.st_ctimespec);
//		}
		if (flags.a != 1 && (char)directory->d_name[0] != (char)'.')
		{
			string = ft_strjoin(string, directory->d_name);
			string = ft_addchar(string, '\t');
		}
		if (flags.a == 1)
		{
			string = ft_strjoin(string, directory->d_name);
			string = ft_addchar(string, '\t');
		}
	}
	ft_output_table(string, w.ws_col > 0 ? w.ws_col : 1);
	return (0);
}