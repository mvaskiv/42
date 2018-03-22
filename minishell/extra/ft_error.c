/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:07:40 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 14:17:24 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_setenv_usage(void)
{
	ft_mini_printf("setenv: usage: setenv [env] [value]\n");
}

static char		*ft_env_name(const char *line)
{
	char	*name;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[9 + i] != '\0')
		i++;
	name = (char*)malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		name[j] = line[9 + j];
		j++;
	}
	name[j++] = '=';
	name[j] = '\0';
	return (name);
}

char		*ft_no_env(const char *line, char ***env)
{
	char	*env_name;
	char	**envp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	envp = *env;
	env_name = ft_env_name(line);
	while (envp[i] != NULL)
		if (ft_strncmp(envp[i++], env_name, ft_strlen(env_name)) == 0)
			return (env_name);
	ft_strdel(&env_name);
	i = 0;
	while (line[i++])
		j = (line[i] == ' ') ? j + 1 : j;
	if (j == 1 && line[9])
		ft_mini_printf("unsetenv: no such environmental variable found\n");
	else
		ft_mini_printf("unsetenv: usage: unsetenv [env]\n");
	return (NULL);
}
