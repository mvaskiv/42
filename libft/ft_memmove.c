
#include "libft.h"

void		*ft_memmove(void *dest, const void *src, unsigned int n)
{
		char					*tmp;
		char					*tmp_dest;
		const char		*tmp_src;
		unsigned int	i;

		i = 0;
		tmp_dest = dest;
		tmp_src = src;
		tmp = malloc(sizeof(char) * n);
		while (i < n)
		{
				tmp[i] = tmp_src[i];
				i++;
		}
		i = 0;
		while (i < n)
		{
				tmp_dest[i] = tmp[i];
				i++;
		}
		free(tmp);
		return (dest);
}
