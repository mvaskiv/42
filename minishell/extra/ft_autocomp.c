/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:28:21 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/17 18:14:00 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

struct termios	original;

void	ft_reset_term(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &original);
}

void	ft_set_term(void)
{
	struct termios	new;

	tcgetattr(STDIN_FILENO, &original);
	atexit(ft_reset_term);

	tcgetattr(STDIN_FILENO, &new);
//	new.c_lflag &= ~(ICANON|ECHO);
	new.c_cc[VEOL] = '\t';
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new);
}