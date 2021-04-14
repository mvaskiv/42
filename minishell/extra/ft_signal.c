/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:40:49 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/30 14:04:05 by jdoekiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signal_int(int sig)
{
	sig = 0;
	ft_mini_printf("\n%s%s%s", BYEL, "Sweet_Lemonade", NRM);
	ft_mini_printf("%s_$>%s ", CYN, BWHT);
}

void	ft_signal_kill(int sig)
{
	sig = 0;
	exit(0);
}

void	ft_signal_caught(int sig)
{
	sig = 0;
}
