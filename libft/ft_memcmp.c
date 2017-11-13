
#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
		unsigned int	i;
		unsigned char	*ss1;
		unsigned char	*ss2;

		i = 0;
		ss1 = (unsigned char *)s1;
		ss2 = (unsigned char *)s2;
		while (i < n)
		{
				if (ss1[i] > ss2[i])
						return (1);
				if (ss2[i] > ss1[i])
						return (-1);
				i++;
		}
		return (0);
}
