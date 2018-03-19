/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/19 17:15:17 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char **env)
{
	int 	i;

	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
	return (1);
}

static char 	*ft_env_name(const char *line)
{
	char 	*name;
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	while (line[9 + i] != '\0')
		i++;
	name = (char*)malloc(sizeof(char) * i);
	while (j < i)
	{
		name[j] = line[9 + j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

void	ft_unsetenv(char ***env, const char *line)
{
	char	**dup;
	char 	**envp = *env;
	char 	*env_name;
	int		i;
	int 	j;

	env_name = ft_env_name(line);
	i = 0;
	while (envp[i++] != NULL);
	dup = (char**)malloc(sizeof(char*) * i - 1);
	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		if ((ft_strstr(envp[i], env_name)))
			i++;
		if (envp[i] != NULL)
			dup[j] = ft_strdup(envp[i]);
		i++;
		j++;
	}
	dup[i] = NULL;
	ft_strdel(&env_name);
	ft_arrclr(*env);
	*env = dup;
}

char	*ft_get_pwd(char **env)
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

char	*ft_get_path(char **env)
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