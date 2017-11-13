
#include "libft.h"

static unsigned int	strlenn(char const *s)
{
		unsigned int		i;

		i = 0;
		while (s[i])
				i++;
		return (i);
}

static int 					strncmpp(const char *s1, const char *s2, unsigned int n)
{
  	unsigned int 	i;

  	i = 0;
		if (n == i)
			return (0);
  	while ((s1[i] || s2[i]) && i < n)
  	{
    	if (s1[i] > s2[i])
      	return (1);
    	if (s2[i] > s1[i])
      	return (-1);
    	i++;
  	}
  	return (0);
}

char								*ft_strnstr(char const *haystack, char const *needle, unsigned int n)
{
		unsigned int	l;

		if (*needle == '\0')
				return ((char *)haystack);
		l = strlenn(needle);
		while (*haystack && n >= l)
		{
				if (strncmpp(haystack, needle, l) == 0)
						return ((char *)haystack);
				haystack++;
				n--;
		}
		return (NULL);
}
