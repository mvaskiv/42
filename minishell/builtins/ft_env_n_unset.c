/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:29:04 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_mini_printf("%s\n", env[i]);
		i++;
	}
	return (1);
}

int			ft_unsetenv(char ***env, const char *line, int i)
{
	char	**dup;
	char	**envp;
	char	*env_name;
	int		j;

	envp = *env;
	if (!(env_name = ft_no_env(line, env)))
		return (1);
	while (envp[i] != NULL)
		i++;
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
	dup[j] = NULL;
	ft_strdel(&env_name);
	ft_arrclr(*env);
	*env = dup;
	return (1);
}
