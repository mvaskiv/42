
#include "libft.h"

static int	strlenn(char const *s)
{
		int		i;

		i = 0;
		while (s[i])
				i++;
		return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
		char		*str;

		if (!(str = (char *)malloc(sizeof(char) * (strlenn(s1) + strlenn(s2) + 1))))
				return (NULL);
		while (*s1)
				*str++ = *s1++;
		while (*s2)
				*str++ = *s2++;
		*str = '\0';
		return (str);
}
