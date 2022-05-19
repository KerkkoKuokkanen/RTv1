/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:01:35 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/04/01 13:25:51 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int	store_rest(char **str, int fd, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		temp = ft_strdup(&str[fd][len + 1]);
		*line = ft_strsub(str[fd], 0, len);
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if (temp[0] == '\0')
		{
			ft_strdel(&temp);
			str[fd] = NULL;
		}
	}
	else
	{
		*line = ft_strsub(str[fd], 0, len);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int	ret_value(int i, int fd, char **str, char **line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && str[fd] == NULL)
		return (0);
	else
		return (store_rest(str, fd, line));
}

static void	str_join_swap(char **str, char *temp, int fd)
{
	char	*temp2;

	if (str[fd] != NULL)
	{
		temp2 = ft_strjoin(str[fd], temp);
		ft_strdel(&str[fd]);
		str[fd] = ft_strdup(temp2);
		ft_strdel(&temp2);
	}
	else
		str[fd] = ft_strdup(temp);
}

int	get_next_line(const int fd, char **line)
{
	int			i;
	char		temp[BUFF_SIZE + 1];
	static char	*str[FILE_DESCRIPTORS];

	if (line == NULL || fd >= FILE_DESCRIPTORS)
		return (-1);
	i = ONE_POSSIBLY_USELESS_RUN_BECAUSE_OF_NORM;
	while (i > 0)
	{
		if (str[fd] && ft_strchr(str[fd], '\n'))
			return (ret_value(i, fd, str, line));
		i = read(fd, temp, BUFF_SIZE);
		temp[i] = '\0';
		if (i > 0)
			str_join_swap(str, temp, fd);
	}
	return (ret_value(i, fd, str, line));
}
