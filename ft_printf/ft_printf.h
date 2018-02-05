#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"

int		ft_printf_engine(va_list arg, const char *format);
int		ft_printf(const char * restrict format, ...);

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
