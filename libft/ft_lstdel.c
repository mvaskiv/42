
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, t_int))
{
	t_list	*to_free;

	if (alst)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			to_free = *alst;
			*alst = (*alst)->next;
			free(to_free);
			te_free = NULL;
		}
	}
}
