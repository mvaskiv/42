/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/21 18:34:42 by mvaskiv          ###   ########.fr       */
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
int 	ft_mod_env(char ***env, const char *line);
void	ft_setenv(char ***envp, const char *line);
void	ft_unsetenv(char ***env, const char *line);
int		ft_cd(const char *line, char ***env);
int		ft_env(char **env);
int		ft_echo(const char *line);

/* PWD_n_PATH -> Env handling */
char	*ft_get_pwd(char **env);
char	*ft_get_path(char **env);
char	*ft_get_oldpwd(char **env);
char	*ft_get_home(char **env);

/* Signals */
void	ft_signal_int(int sig);
void	ft_signal_caught(int sig);

/* Errors */
void	ft_setenv_usage(void);

/* help_me */
int		ft_count_quotes(const char *line);
char	*ft_no_env(const char *line, char ***env);

int		ft_exit(const char *line);
char	**ft_arrdup(char **arr);

/* Easter_Eggs */
void	ft_fun_fact();
void	ft_my_horse(char **env, char **line);

#endif
