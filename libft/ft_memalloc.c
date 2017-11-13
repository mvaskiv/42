
#include "libft.h"

void		*ft_memalloc(unsigned int size)
{
		void					*str;
		unsigned int	i;

		i = 0;
		if(!(str = malloc(size)))
				return (NULL);
		while (i < size)
				((char *)str)[i++] = '\0';
		return (str);
}
