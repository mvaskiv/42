/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 18:08:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <ncurses.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "unistd.h"


typedef struct			s_com
{
	char				*name;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_com;

/* Welcome_message */
void	ft_welcome(char **line, char *name);

/* Pathfinders */
char	*ft_check_path(char *path, int x);
char	*ft_find_path(char **input);

/* Forkers */
void	ft_fork(char **input, char **env);

/* Builtins */
int		ft_cd(char *line, char **name);
int		ft_env(char **env);
int		ft_echo(char *line);
char	**ft_setenv(char ***envp, char *line);
int		ft_unsetenv(char **env, char *line);

/* Signals */
void	ft_signal(int signal);

/* help_me */
int 	ft_count_quotes(char *line);

#endif
