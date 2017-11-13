
#include "libft.h"

char		*ft_strnew(unsigned int size)
{
		char		*str;

		if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
				return (NULL);
		while (*str)
				*str++ = '\0';
		*str = '\0';
		return (str);
}
