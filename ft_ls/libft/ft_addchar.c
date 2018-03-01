#include "includes/libft.h"

char 	*ft_addchar(char **string, char c)
{
	char 	*str = NULL;
	int 	i;

	i = 0;
	if (*string != '\0')
		i = ft_strlen(*string);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (*string)
		ft_memmove(str, *string, i);
	ft_strdel(string);
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}