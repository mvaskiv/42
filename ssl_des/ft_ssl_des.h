
#ifndef FT_SSL_DES_H
# define FT_SSL_DES_H

# define BUFF_SIZE 4096

# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct		s_opt
{
	int					len;
	int					encrypt;
	int					base64;
	unsigned char		*b64_s;
	int					offset;
	int					fd_in;
	int					fd_out;
	int					padded;
	int					des_cbc;
	int					key_flag;
	int					iv_flag;
	int					empty_read;
	unsigned long long	key;
	unsigned long long	iv;
}					t_opt;

void				putnstr_fd(unsigned char const *s, int fd, int len);
unsigned char		*read_data(t_opt *opt, int ret);
long long			ft_power(long long nbr, int power);
void				des_cbc(int argc, char **argv);
void				des_processes(unsigned long long s_blk, t_opt *opt);
unsigned long long	permutate(unsigned long long in, int *permutation,
													int tab_size, int size);
void				get_permutate_subkeys(t_opt *opt,
												unsigned long long *subkeys);
void				des(int argc, char **argv, int des_cbc);
void				b64_encrypt(unsigned char *s, t_opt *opt, int j);
void				b64_decrypt(unsigned char *s, t_opt *opt, int i, int j);
void				base64(int argc, char **argv);
void				errors(char **argv, int i, int error);
void				hexstr_int(t_opt *opt, char *s, int specifier);
void				populate_data(int argc, char **argv, t_opt *opt);
void				initialize_opt(t_opt *opt, int des_cbc);
int					main(int argc, char **argv);
#endif
