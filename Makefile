# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 15:19:51 by kkuokkan          #+#    #+#              #
#    Updated: 2022/05/17 15:14:27 by kkuokkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/sphere1.c srcs/angles.c srcs/get_next_line.c \
		srcs/read_file.c srcs/plane.c srcs/cylinder.c srcs/cone.c \
		srcs/draw.c srcs/add_angle_abs.c srcs/sign_tools.c \
		srcs/coordinates.c srcs/light_and_lines.c srcs/obj_and_cam.c \
		srcs/intersect.c srcs/vec_and_coord.c srcs/sign_cone.c srcs/init.c \
		srcs/get_c.c srcs/misc.c srcs/s_check.c
F_WORK = -framework OpenGL -framework Appkit
L_SDL = -l SDL2-2.0.0 -l SDL2_image-2.0.0
HEADERS = -I sdl_include -I srcs/rtv1.h -I libft/libft.h
LIBS = -L sdl_lib libft/libft.a

all:
	@@gcc $(FLAGSS) $(SRCS) $(HEADERS) $(LIBS) $(L_SDL) $(F_WORK) -flto -O3