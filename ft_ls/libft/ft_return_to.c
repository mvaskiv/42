/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:22:12 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:22:20 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_return_to(char *string, char c)
{
	char	*string_backup;

	string_backup = string;
	if (!string || !c)
		return (NULL);
	while (string && *string)
	{
		if (*string-- == (char)c)
			return (string);
	}
	string = string_backup;
	return (string);
}
