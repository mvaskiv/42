/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:14:15 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/20 16:12:39 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_free;

	if (alst && del)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			to_free = *alst;
			*alst = (*alst)->next;
			free(to_free);
			to_free = NULL;
		}
	}
}
