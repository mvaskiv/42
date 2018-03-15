/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:49:46 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 19:36:57 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char 	*ft_check_path(char *path, int x)
{
	static int 	i = 0;
	int 		j;
	char 		*possible;

	if (x == 1)
	{
		i = 0;
		return (NULL);
	}
	possible = (char*)malloc(sizeof(char) * 128);
	j = 0;
	while (path[i] != ':' && path[i] != '\0')
		possible[j++] = path[i++];
	possible[j] = '\0';
	if (i >= ft_strlen(path))
	{
		i = 0;
		ft_strdel(&possible);
		return (NULL);
	}
	else
		i++;
	return (possible);
}

char	*ft_find_path(char **input)
{
	char 		*name;
	char 		*fullname;
	char 		*path;

	path = NULL;
	name = ft_strjoin("/", input[0]);
	while (1)
	{
		path = ft_check_path(getenv("PATH"), 0);
		if (path == NULL)
		{
			input[1] = input[0];
			return (NULL);
		}
		fullname = ft_strjoin(path, name);
		if (access(fullname, X_OK) == 0)
		{
			ft_check_path(NULL, 1);
			ft_strdel(&path);
			ft_strdel(&name);
			return (fullname);
		}
		ft_strdel(&fullname);
		ft_strdel(&path);
	}
	return (NULL);
}