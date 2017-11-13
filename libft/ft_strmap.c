
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
				if (f(s[i]))
				{
						str[i] = f(s[i]);
						i++;
				}
		}
		return (str);
}
