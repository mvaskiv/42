/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_n_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 13:53:19 by mvaskiv          ###   ########.fr       */
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

char	**ft_unsetenv(char ***env, char *line)
{
	int 	i;

	i = 0;
	while (!(ft_strstr(env[i++], (line + 9))));
	return (1);
}
