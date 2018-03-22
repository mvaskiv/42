/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:19:47 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/20 18:01:49 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fun_fact(void)
{
	ft_putendl("However, here is a fun fact for you:");
	ft_putendl("Banging your head against the wall");
	ft_putendl("burns 150 calories an hour");
	ft_putstr(BWHT);
}

int		ft_exit(const char *line)
{
	if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
		exit(0);
	if (line[0] == 'q' && line[1] == 'u' && line[2] == 'i' && line[3] == 't')
	{
		ft_putendl("I know what you mean. BA-DUM-TSSS");
		exit(0);
	}
	return (0);
}

void	ft_my_horse(char **env, char **line)
{
	pid_t	pid;

	pid = getpid();
	system("afplay /Users/mvaskiv/Downloads/horse.mp3");
	ft_strdel(line);
	if (signal(SIGINT, ft_signal_caught))
	{
		kill(pid, SIGINT);
		return ;
	}
}
