
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
		char		*str;
		int			i;

		i = 0;
		while (s[i])
				i++;
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
				return (NULL);
		i = 0;
		while (s)
		{
				if (f(i, s[i]))
				{
						str[i] = f(i, s[i]);
						i++;
				}
				s++;
		}
		return (str);
}
