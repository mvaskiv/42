/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/20 18:43:04 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
	return (1);
}

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

void			ft_unsetenv(char ***env, const char *line)
{
	char	**dup;
	char	**envp;
	char	*env_name;
	int		i;
	int		j;

	envp = *env;
	if (!(env_name = ft_no_env(line, env)))
		return ;
	i = 0;
	while (envp[i++] != NULL);
	dup = (char**)malloc(sizeof(char*) * i);
	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], env_name, ft_strlen(env_name)) == 0)
			i++;
		else if (envp[i] != NULL)
			dup[j++] = ft_strdup(envp[i++]);
	}
	dup[i] = NULL;
	ft_strdel(&env_name);
	ft_arrclr(*env);
	*env = dup;
}