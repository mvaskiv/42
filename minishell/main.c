/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/14 17:47:52 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char 	*ft_check_path(char *path)
{
	static int 		i = 0;
	int 		j;
	char 		*possible;

	possible = (char*)malloc(sizeof(char) * 128);
	j = 0;
	while (path[i] != ':' && path[i] != '\0')
		possible[j++] = path[i++];
	possible[j] = '\0';
	i++;
	j = 0;
	return (possible);
}

char	*ft_find_path(char *input)
{
	char 		*name;
	char 		*fullname;

	name = ft_strdup(input);
	name = ft_strjoin("/", name);
	while (1)
	{
		fullname = ft_strjoin(ft_check_path(getenv("PATH")), name);
		if (access(fullname, X_OK) == 0)
			return (fullname);
		ft_strdel(&fullname);
	}
	return (NULL);
}

int		main(int argc, char **argv, char **envp)
{
	char 	**input;
	char 	*line;
	char 	*env[] = {"PATH=/bin", NULL};
	pid_t 	pid;
	extern char	**environ;

	ft_mini_printf("%s%s%s", YEL, getenv("USER"), NRM);
	ft_mini_printf("%s_$>%s ", CYN, NRM);
	int i = 0;
	get_next_line(0, &line);
	input = ft_strsplit(line, ' ');
//	pid = fork();
	input[0] = ft_find_path(input[0]);
	execve(input[0], &input[0], environ);
}
