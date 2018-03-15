/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:45:53 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 12:49:08 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "unistd.h"

/* Welcome_message */
void	ft_welcome(char **line, char *name);

/* Pathfinders */
char	*ft_check_path(char *path);
char	*ft_find_path(char *input);

/* Forkers */
void	ft_fork(char **input, char **env);

/* Builtins */
void	ft_cd(char *line, char **name);
void	ft_echo(char *line);

void 	ft_env(char **env);
void	ft_setenv(char **env, char *line);


#endif
