
#include "ft_ssl_des.h"

void	putnstr_fd(unsigned char const *s, int fd, int len)
{
	int i;

	if (s)
	{
		i = 0;
		while (i < len)
			write(fd, &s[i++], 1);
	}
}
