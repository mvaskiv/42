#include "includes/libft.h"

void	*ft_return_to(char *string, char c)
{
	char 	*string_backup;

	string_backup = string;
	if (!string || !c)
		return (NULL);
	while (string && *string--)
	{
		if (*string == (char)c)
			return (string);
	}
	string = string_backup;
	return (string);
}