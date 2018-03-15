/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 13:50:35 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "unistd.h"

/* Welcome_message */
void	ft_welcome(char **line, char *name);

/* Pathfinders */
char	*ft_check_path(char *path, int x);
char	*ft_find_path(char **input);

/* Forkers */
void	ft_fork(char **input, char **env);

/* Builtins */
void	ft_cd(char *line, char **name);
void	ft_echo(char *line);
void	ft_env(char **env);
void	ft_setenv(char **env, char *line);
void	ft_unsetenv(char **env, char *line);

/* Signals */
void	ft_signal(int signal);


/* help_me */

int 	ft_count_quotes(char *line);

#endif
