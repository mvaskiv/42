/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/16 16:12:11 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "unistd.h"

/* Welcome_message */
void	ft_welcome(char **line, char *name);

/* Pathfinders */
char	*ft_check_path(char *path, int x);
void	ft_find_path(char **input);

/* Forkers */
void	ft_fork(char **input, char **env);

/* Builtins */
int		ft_cd(const char *line, char **name);
int		ft_env(char **env);
int		ft_echo(const char *line);
char	**ft_setenv(char ***envp, const char *line);
char	**ft_unsetenv(char ***env, const char *line);

/* Signals */
void	ft_signal(int signal);

/* help_me */
int		ft_count_quotes(const char *line);

#endif
