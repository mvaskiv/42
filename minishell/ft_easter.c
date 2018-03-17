/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:19:47 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/17 13:37:32 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_fun_fact()
{
	int		i;
	char	*fact[] = {"Banging your head against the wall burns 150 calories an hour",
						"The average women uses her height of lipstick every 5 years",
						"Cherophobia is the fear of fun",
						"Heart attacks are more likely to happen on Mondays",
						"If you consistently fart for 6 years & 9 months, enough gas is produced to create energy of an atomic bomb",
						"If you leave everything to the last minute - it will only take a minute",
						"The average person walks the equivalent of twice around the globe in a lifetime",
						"Every year more than 2500 left-handed people are killed from using right-handed products",
						NULL};

	i = (rand() % 8);
	ft_putendl("So, here is a random fun fact for you:");
	ft_putendl(fact[i]);
	ft_putstr(BWHT);
}