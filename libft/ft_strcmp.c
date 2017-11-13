
#include "libft.h"

int 		ft_strcmp(const char *s1, const char *s2)
{
  	int 	i;

  	i = 0;
  	while (s1[i] || s2[i])
  	{
    	if (s1[i] > s2[i])
      	return (1);
    	if (s2[i] > s1[i])
      	return (-1);
    	i++;
  	}
  	return (0);
}
