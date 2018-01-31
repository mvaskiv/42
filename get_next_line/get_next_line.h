/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:19:17 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/01/31 15:58:12 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct			s_storage
{
	char				*content;
	int				fd;
	struct s_storage		*next;
}						t_storage;

int		get_next_line(const int fd, char **line);

#endif
