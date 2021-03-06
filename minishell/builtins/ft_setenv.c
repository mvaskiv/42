/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:10:14 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*ft_env_name(const char *line)
{
	char	*name;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i] != '=')
		i++;
	name = (char*)malloc(sizeof(char) * i + 1);
	while (j <= i)
	{
		name[j] = line[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

char			**ft_change_env(char ***env, const char *line, int i)
{
	char	**dup;
	char	**envp;
	int		j;

	j = 0;
	envp = *env;
	while (envp[j] != NULL)
		j++;
	dup = (char**)malloc(sizeof(char*) * (j + 1));
	j = 0;
	while (envp[j] != NULL)
	{
		dup[j] = ft_strdup(envp[j]);
		j++;
		if (j == i)
			dup[j++] = ft_strdup(line);
	}
	dup[j] = NULL;
	return (dup);
}

char			**ft_new_env(char ***env, const char *line, int i)
{
	char	**dup;
	char	**envp;

	i = 0;
	envp = *env;
	while (envp[i] != NULL)
		i++;
	dup = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (envp[i] != NULL)
	{
		dup[i] = ft_strdup(envp[i]);
		i++;
	}
	dup[i++] = ft_strdup(line);
	dup[i] = NULL;
	return (dup);
}

void			ft_setenv(char ***env, const char *line)
{
	int		i;
	char	**dup;
	char	**envp;
	char	*env_name;

	i = 0;
	envp = *env;
	env_name = ft_env_name(line);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], env_name, ft_strlen(env_name)) == 0)
		{
			ft_strdel(&env_name);
			dup = ft_change_env(env, line, i);
			ft_arrclr(*env);
			*env = dup;
			return ;
		}
		i++;
	}
	dup = ft_new_env(env, line, i);
	ft_strdel(&env_name);
	ft_arrclr(*env);
	*env = dup;
}

int				ft_mod_env(char ***env, const char *line)
{
	char	*value;
	char	**input;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i++])
		j = (line[i] == ' ') ? j + 1 : j;
	if (j != 2 || !(line[7]) || !(line[8]))
		ft_setenv_usage();
	else
	{
		input = ft_strsplit(line, ' ');
		value = ft_set_env_val(input);
		ft_setenv(env, value);
		ft_strdel(&value);
		ft_arrclr(input);
	}
	return (1);
}
