
#include "ft_ssl_des.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("usage: ./ft_ssl command [command opts] [command args]\n");
	else
	{
		if (ft_strcmp(argv[1], "base64") == 0)
			base64(argc, argv);
		else if (ft_strcmp(argv[1], "des") == 0
			|| ft_strcmp(argv[1], "des-ecb") == 0)
			des(argc, argv, 0);
		else if (ft_strcmp(argv[1], "des-cbc") == 0)
			des(argc, argv, 1);
		else
		{
			ft_putstr("ft_ssl: Error: '");
			ft_putstr(argv[1]);
			ft_putstr("' is an invalid command.\n\nStandard commands:\n\n");
			ft_putstr("Message Digest commmands:\n\nCipher commands:\n");
			ft_putstr("base64\ndes\ndes-ecb\ndes-cbc\n");
		}
	}
	return (0);
}
