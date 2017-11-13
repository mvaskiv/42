
#include "libft.h"

static char		*strncpyy(char *dest, const char *src, unsigned int n)
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

char		*ft_strsub(char const *s, unsigned int start, unsigned int len)
{
		char		*str;

		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
				return (NULL);
		strncpyy(str, &(s[start]), len);
		str[len] = '\0';
		return (str);
}
