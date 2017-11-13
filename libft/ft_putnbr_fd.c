
#include "libft.h"

static void putcharr(char c, int fd)
{
		write(fd, &c, 1);
}

static void		putstrr(char const *s, int fd)
{
		int		i;

		i = 0;
		while (s[i])
				i++;
		write(fd, s, i);
}

void		ft_putnbr_fd(int n, int fd)
{
		int		i[10];
		int		j;

		j = 0;
		if (n == -2147483648)
		{
				putstrr("-2147483648", fd);
				return ;
		}
		if (n < 0)
		{
			putcharr('-', fd);
			n = -n;
		}
		while (n)
		{
			i[j++] = n % 10;
			n /= 10;
		}
		i[j] = '\0';
		if (j == 0)
			putcharr('0', fd);
		while (--j >= 0)
			putcharr(i[j] + '0', fd);
}
