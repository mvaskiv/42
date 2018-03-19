/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/19 14:25:32 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <termios.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "unistd.h"

/* Welcome_message */
void	ft_welcome(char **line);

/* Check_execs */
void	ft_check_exec(char **line, char ***env);
void	ft_exec_local(char **line, char ***env);

/* Pathfinders */
char	*ft_check_path(char *path, int x);
void	ft_find_path(char **input, char *path_env);

/* Forkers */
void	ft_fork(char **input, char **env);
int		ft_handle_few(const char *line, char **env);

/* Builtins */
char	**ft_setenv(char ***envp, const char *line);
void	ft_set_env(char ***env, const char *line);

char	**ft_unsetenv(char ***env, const char *line);
int		ft_cd(const char *line);
int		ft_env(char **env);
int		ft_echo(const char *line);

/* PWD_n_PATH -> Env handling */
char	*ft_get_pwd(char **env);
char	*ft_get_path(char **env);

/* Signals */
void	ft_signal(int signal);

/* help_me */
void	ft_fun_fact();
int		ft_count_quotes(const char *line);
int		ft_exit(const char *line);
char	**ft_arrdup(char **arr);

//void	ft_set_term(void);

#endif
