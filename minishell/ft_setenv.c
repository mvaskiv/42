/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:08:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 18:09:11 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_setenv(char ***env, char *line)
{
	int		i;
	char	**dup;
	char 	**envp = *env;

	i = 0;
	while (envp[i] != NULL)
		i++;
	dup = (char**)malloc(sizeof(char*) * i + 1);
	i = 0;
	while (envp[i] != NULL)
	{
		dup[i] = ft_strdup(envp[i]);
		i++;
	}
	dup[i++] = ft_strdup(line + 7);
	dup[i] = NULL;
	return (dup);
}
