
#include "libft.h"

void		*ft_memchr(const void *s, int c, unsigned int n)
{
		unsigned int	i;
		unsigned char	*str;

		i = 0;
		str = (unsigned char *)s;
		while (i < n)
		{
				if (str[i] == (unsigned char)c)
						return ((void *)&str[i]);
				i++;
		}
		return (NULL);
}
