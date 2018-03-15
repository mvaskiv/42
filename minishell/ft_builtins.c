/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:33:33 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 12:34:00 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd(char ***env, char *line)
{
	int		i;
	char 	**envp;

	i = 0;
	envp = *env;
	while (!(ft_strstr(envp[i++], "PWD")));
	envp[i - 1] = ft_strjoin(ft_strjoin(envp[i - 1], "/"), ft_strdup(line + 3));
}
