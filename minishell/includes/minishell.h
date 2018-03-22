/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 15:51:26 by mvaskiv          ###   ########.fr       */
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

void	ft_welcome(char **line);

void	ft_check_exec(char **line, char ***env);
void	ft_exec_local(char **line, char ***env);

char	*ft_check_path(char *path, int x);
void	ft_find_path(char **input, char *path_env);

void	ft_fork(char **input, char **env);
int		ft_handle_few(const char *line, char **env);

int		ft_mod_env(char ***env, const char *line);
void	ft_setenv(char ***envp, const char *line);
int		ft_unsetenv(char ***env, const char *line, int i);
int		ft_cd(const char *line, char ***env);
int		ft_env(char **env);
int		ft_echo(const char *line, char ***env);
int		ft_echo_env(const char *line, int i, char ***env);
int		ft_echo_quotes(const char *line, int i, char ***env);

char	*ft_get_pwd(char **env);
char	*ft_get_path(char **env);
char	*ft_get_oldpwd(char **env);
char	*ft_get_home(char **env);

void	ft_signal_int(int sig);
void	ft_signal_caught(int sig);

void	ft_setenv_usage(void);
char	*ft_set_env_val(char **input);

int		ft_count_quotes(const char *line);
char	*ft_no_env(const char *line, char ***env);

int		ft_exit(const char *line);
char	**ft_arrdup(char **arr);

void	ft_fun_fact();
void	ft_my_horse(char **env, char **line);

#endif
