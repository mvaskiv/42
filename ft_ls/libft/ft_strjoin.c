/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:04:59 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 18:06:58 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strjoin(char *s1, char const *s2)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	str = ft_strdup(s1);
	ft_strcat(str, s2);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';

//	s1 = NULL;
//	s2 = NULL;
	return (str);
}
