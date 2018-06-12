
#include "ft_ssl_des.h"


void		usage_error(void)
{
	ft_putstr("usage: enc -ciphername [-ade] [-base64] [-i file] [-v IV] ");
	ft_putstr("[-k key] [-o file]\n\n");
	ft_putstr("-a          Process base64 encoding/decoding (alias -base64)\n");
	ft_putstr("-d          Decrypt the input data\n");
	ft_putstr("-e          Encrypt the input data (default)\n");
	ft_putstr("-i          Input file to read from (default stdin)\n");
	ft_putstr("-k          Key to use, specified as a hexidecimal string\n");
	ft_putstr("-o          Output file to write to (default stdout)\n");
	ft_putstr("-v          IV to use, specified as a hexidecimal string\n\n");
	ft_putstr("Valid cipher values:\n\n");
	ft_putstr("-des\n-des-cbc\n-des-ecb\n\n");
}

void		errors(char **argv, int j, int error)
{
	if (error == 0)
	{
		ft_putstr("unknown option '");
		ft_putstr(argv[j]);
		ft_putstr("'\n");
	}
	if (error == 1)
	{
		ft_putstr("missing file argument for ");
		ft_putendl(argv[j - 1]);
	}
	if (error == 2)
	{
		ft_putstr("missing key argument for ");
		ft_putendl(argv[j - 1]);
	}
	if (error == 0 || error == 1 || error == 2 || error == 3)
		usage_error();
	if (error == 4)
	{
		ft_putstr(argv[j]);
		ft_putstr(": No such file or directory\n");
	}
	exit(1);
}
