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
	c = win_width / i;
	while (arr[j])
	{
		printf("%-*s\t", i, arr[j]);
		j++;
		if (c != 0 && (j % c) == 0)
			printf("\n");
	}
	//printf("\n");
	return (0);
}

int 	main(int argc, char **argv)
{
	struct winsize	w;
	struct dirent	*directory;
	char 	*string = NULL;
	DIR		*dir;

	if (argc > 1 && argv[1][0] != '-')
		dir = opendir(argv[1]);
	else if (argc > 2 && argv[1][0] != '-')
		dir = opendir(argv[2]);
	else
		dir = opendir(getenv("PWD"));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while ((directory = readdir(dir)))
	{
		if ((char)directory->d_name[0] != (char)'.') {
			string = ft_strjoin(string, directory->d_name);
			string = ft_addchar(string, '\t');
		}
	}
	ft_output_table(string, w.ws_col > 0 ? w.ws_col : 2);
//	ft_putendl(string);
	return (0);
}