/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:14:31 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/20 16:11:30 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
		{
			new->next = *alst;
			*alst = new;
		}
	}
}
