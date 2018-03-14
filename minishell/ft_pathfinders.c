/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:49:46 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/14 18:41:23 by mvaskiv          ###   ########.fr       */
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
	i >= ft_strlen(path) ? i = 0 : i++;
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
		{
			ft_strdel(&name);
			return (fullname);
		}
		ft_strdel(&fullname);
	}
	return (NULL);
}
