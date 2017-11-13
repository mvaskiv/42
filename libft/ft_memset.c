
#include "libft.h"

void		*ft_memset(void *s, int c, unsigned int n)
{
		unsigned int		i;

		i = 0;
		while (i < n)
			((char *)s)[i++] = (unsigned char)c;
		return (s);
}
