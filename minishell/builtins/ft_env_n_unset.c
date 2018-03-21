/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/21 18:15:48 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_env(char **env)
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
	dup = (char**)malloc(sizeof(char*) * i - 1);
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
}