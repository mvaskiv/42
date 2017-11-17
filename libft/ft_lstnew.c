
#include "libft.h"

staticvoid		*memallocc(unsigned int size)
{
	void			*str;
	unsigned int	i;

	i = 0;
	str = malloc(size);
	if (str)
	{
		while (i < size)
			((char *)str)[i++] = 0;
	}
	return (str);
}

static void		*memcpyy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	char			*tmp_dest;
	const char		*tmp_src;

	i = 0;
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}

t_list				*ft_lstnew(void const *content, t_int content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = memallocc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (content)
	{
		memcpyy(new->content, content, content_size);
		new->content_size = content ? content_size : 0;
		new->next = NULL;
	}
	return (new);
}
