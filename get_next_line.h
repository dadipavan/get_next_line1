/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <tidadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:39:28 by tidadi            #+#    #+#             */
/*   Updated: 2019/05/13 10:37:55 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 10
# define MAX_FD 4864
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int		get_next_line(int const fd, char **line);

int			gnl_line(char **stack, char **line);

#endif
