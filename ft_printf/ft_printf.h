
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# define BLACK      "\033[30;"
//# define RED        "\033[31;"
//# define GREEN      "\033[32;"
//# define YELLOW     "\033[33;"
//# define BLUE       "\033[34;"
//# define PURPLE     "\033[35;"
//# define DKGREEN    "\033[6;"
//# define WHITE      "\033[7;"
//# define CYAN       "\x1b[36m"
//
//# define BBLACK      "40m"
//# define BRED        "41m"
//# define BGREEN      "42m"
//# define BYELLOW     "43m"
//# define BBLUE       "44m"
//# define BPURPLE     "45m"
//# define B_DKGREEN    "46m"
//# define BWHITE      "47m"
//
//# define RESET        "\033[0m"

# define	HH	"hh"
# define	H	"h"
# define	LL	"ll"
# define	L	"l"
# define	J	"j"
# define	Z	"z"

//# define	CONVERT	int	ft_convert(va_list arg, const char * format, char **string, int width)

# include <stdarg.h>
# include "libft/includes/libft.h"

int		ft_printf(const char * restrict format, ...);
int		ft_printf_engine(va_list arg, const char *format);
int     ft_set_size(const char *format, va_list arg, char **string, int width, int len);
int 	ft_convert(va_list arg,
                  const char * format, char **string, int width);
int 	ft_convert_size_set(void *data,
				  const char * format, char **string, int width);
char	*ft_set_width(va_list arg,
					const char * format, char *string, int width);

//void	(*flag[5]) = {
//		flag_hash, flag_zero, flag_minus, flag_plus, flag_space
//}
//
//void	(*length[6]) = {
//		len_hh, len_h, len_ll, len_l, len_j, len_z
//}
//
//void	(*specifier[14]) = {
//		con_s, con_S, con_p, con_d, con_D, con_i, con_o,
//		con_O, con_u, con_U, con_x, con_X, con_c, con_C
//}

#endif
