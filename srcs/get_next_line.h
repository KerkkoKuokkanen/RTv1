/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:04:27 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/04/04 12:52:14 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50
# define FILE_DESCRIPTORS 4096
# define ONE_POSSIBLY_USELESS_RUN_BECAUSE_OF_NORM 1

# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif