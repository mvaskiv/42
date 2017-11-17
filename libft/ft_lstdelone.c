
#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, t_int))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
