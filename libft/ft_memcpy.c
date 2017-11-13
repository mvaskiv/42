
#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, unsigned int n)
{
		unsigned int		i;
		char						*tmp_dest;
		const char			*tmp_src;

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
