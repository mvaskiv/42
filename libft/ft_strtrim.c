
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

char		*ft_strtrim(char const *s)
{
			int		i;
			char	*str;

			i = 0;
			while (*s == ' ' || *s ==  '\n' || *s == '\t')
					s++;
			while (s[i])
					i++;
			while (i > 0
					&& (s[i - 1] == ' ' || s[i - 1] ==  '\n'
				 	|| s[i - 1] == '\t'))
					i--;
			if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
					return (NULL);
			strncpyy(str, s, i);
			str[i] = '\0';
			return (str);
}
