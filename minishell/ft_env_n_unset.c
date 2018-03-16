/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 14:23:18 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_env(char **env)
{
	int 	i;

	i = 0;
	while (env[i] != NULL)
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

char	**ft_unsetenv(char ***env, char *line)
{
	char	**dup;
	char 	**envp = *env;
	char 	*env_name;
	int		i;

	env_name = ft_env_name(line);
	i = 0;
	while (envp[i++] != NULL);
	dup = (char**)malloc(sizeof(char*) * i);
	i = 0;
	while (envp[i] != NULL)
	{
		dup[i] = ft_strdup(envp[i]);
		i++;
		if (ft_strstr(envp[i], env_name))
			i++;
	}
	dup[i] = NULL;
	ft_strdel(&env_name);
	ft_arrclr(*env);
	return (dup);
}
