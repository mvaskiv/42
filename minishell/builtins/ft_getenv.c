/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:24:03 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/21 17:24:37 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*ft_get_pwd(char **env)
{
	int		i;
	char 	*pwd;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == 'P' && ft_strstr(env[i], "PWD="))
		{
			pwd = ft_strdup(env[i] + 4);
			return (pwd);
		}
		i++;
	}
	return (NULL);
}

char			*ft_get_path(char **env)
{
	int 	i;
	char 	*path;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == 'P' && ft_strstr(env[i], "PATH="))
		{
			path = ft_strdup(env[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char			*ft_get_oldpwd(char **env)
{
	int 	i;
	char 	*path;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == 'O' && ft_strstr(env[i], "OLDPWD="))
		{
			path = ft_strdup(env[i] + 7);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char			*ft_get_home(char **env)
{
	int 	i;
	char 	*path;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == 'H' && ft_strstr(env[i], "HOME="))
		{
			path = ft_strdup(env[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}
