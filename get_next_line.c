/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidadi <tidadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:25:00 by tidadi            #+#    #+#             */
/*   Updated: 2019/05/13 11:06:27 by tidadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			gnl_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*strchr_stack;
	int				i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = *stack;
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		*p[MAX_FD];
	char			*h;
	int				ret;
	char			*tmp;
	int               i;

	if (fd < 0 || (read(fd, p[fd], 0) < 0) || !line || !(h = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (!p[fd])
		p[fd] = ft_strnew(0);
	while (i < BUFF_SIZE)
		h[i++] = '\0';
	while (gnl_line(&p[fd], line) == 0 && (ret = read(fd, h, BUFF_SIZE)) > 0)
	{
		h[ret] = '\0';
		tmp = p[fd];
		p[fd] = ft_strjoin(p[fd], h);
		free(tmp);
    }
    free(heap);
	if (ret != 0 || p[fd] == NULL || p[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = p[fd];
	p[fd] = NULL;
	return (1);
}