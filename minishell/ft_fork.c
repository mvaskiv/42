/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:37 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 12:32:37 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_fork(char **input, char **env)
{
	int 	status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_putendl("error");
	else if (pid == 0)
	{
		execve(input[0], &input[0], env);
		wait(&status);
	}
	else
		waitpid(pid, &status, 0);
}