/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:10:14 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/19 14:33:00 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char 	*ft_env_name(const char *line)
{
	char 	*name;
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	while (line[7 + i] != '=')
		i++;
	name = (char*)malloc(sizeof(char) * i + 1);
	while (j <= i)
	{
		name[j] = line[7 + j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

char	**ft_change_env(char ***env, const char *line, int i)
{
	char	**dup;
	char 	**envp;
	int		j;

	j = 0;
	envp = ft_arrdup(*env);
	while (envp[j++] != NULL);
	dup = (char**)malloc(sizeof(char*) * j);
	j = 0;
	if (j == i)
		dup[j++] = ft_strdup(line + 7);
	while (envp[j] != NULL)
	{
		dup[j] = ft_strdup(envp[j]);
		j++;
		if (j == i)
			dup[j++] = ft_strdup(line + 7);
	}
	dup[j] = NULL;
	ft_arrclr(envp);
	return (dup);
}

char 	**ft_new_env(char ***env, const char *line, int i)
{
	char 	**dup;
	char 	**envp;

	dup = (char**)malloc(sizeof(char*) * i + 1);
	i = 0;
	envp = ft_arrdup(*env);
	while (envp[i])
	{
		dup[i] = ft_strdup(envp[i]);
		i++;
	}
	dup[i++] = ft_strdup(line + 7);
	dup[i] = NULL;
	ft_arrclr(envp);
	return (dup);
}

char	**ft_setenv(char ***env, const char *line)
{
	int		i;
	char	**dup = NULL;
	char 	**envp;
	char 	*env_name;

	i = 0;
	envp = ft_arrdup(*env);
	env_name = ft_env_name(line);
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], env_name))
		{
			dup = ft_change_env(env, line, i);
			ft_strdel(&env_name);
			ft_arrclr(*env);
			return (dup);
		}
		i++;
	}
	dup = ft_new_env(env, line, i);
	ft_strdel(&env_name);
	ft_arrclr(envp);
	ft_arrclr(*env);
	return (dup);
}
