
#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, unsigned int n)
{
		unsigned int		i;

		i = 0;
		while (src[i] && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
			dest[i++] = '\0';
		return (dest);
}
