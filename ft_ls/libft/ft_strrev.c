/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:10:23 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:10:23 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrev(char *string)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	output = ft_strnew(3);
	while (string[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		output[j] = (char)string[i];
		j++;
		i--;
	}
	output[j] = '\0';
	free(string);
	return (output);
}
