/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:58:02 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	if (s[i] != '\0')
		while (s[i])
			write(1, &s[i++], 1);
	write(1, "\n", 1);
}
