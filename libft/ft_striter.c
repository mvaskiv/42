
#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
		int		i;

		i = 0;
		if (s)
		{
				while (s[i])
						f(s++);
		}
}
