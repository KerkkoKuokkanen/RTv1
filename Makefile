# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 15:19:51 by kkuokkan          #+#    #+#              #
#    Updated: 2022/05/19 12:05:46 by kkuokkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/sphere1.c srcs/angles.c srcs/get_next_line.c \
		srcs/read_file.c srcs/plane.c srcs/cylinder.c srcs/cone.c \
		srcs/draw.c srcs/add_angle_abs.c srcs/sign_tools.c \
		srcs/coordinates.c srcs/light_and_lines.c srcs/obj_and_cam.c \
		srcs/intersect.c srcs/vec_and_coord.c srcs/sign_cone.c srcs/init.c \
		srcs/get_c.c srcs/misc.c srcs/s_check.c
OBJ = $(SRCS:.c=.o)
HDR = srcs/rtv1.h
F_WORK =  -lmlx -framework OpenGL -framework Appkit
L_SDL = -l SDL2-2.0.0 -l SDL2_image-2.0.0
HEADERS = -I ./srcs -I ./libft
LIBS = -L sdl_lib libft/libft.a
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all: $(NAME)

$(NAME): libft/libft.a $(OBJ) $(HDR)
		@gcc $(FLAGS) $(F_WORK) $(FRAMEWORKS) $(OBJ) libft/libft.a -o $(NAME)

.c.o: $(HDR)
		@gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean:
	@make fclean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

libft/libft.a:
	@make -C libft

re: fclean all