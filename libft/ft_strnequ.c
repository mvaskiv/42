/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:10:11 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:08:33 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2,
	unsigned int n)
{
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
