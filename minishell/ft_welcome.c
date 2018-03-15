/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:44 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/15 12:31:44 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_welcome(char **line, char *name)
{
	ft_mini_printf("%s%s%s", YEL, name, NRM);
	ft_mini_printf("%s_$>%s ", CYN, CYN);
	get_next_line(0, line);
}