/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:19:17 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 16:22:57 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/includes/libft.h"

# define BUFF_SIZE 16

typedef struct			s_storage
{
	char				*content;
	int					fd;
	struct s_storage	*next;
}						t_storage;

int						get_next_line(const int fd, char **line);

#endif
