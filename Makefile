# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpankewi <mpankewi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 09:57:11 by mpankewi          #+#    #+#              #
#    Updated: 2022/11/22 11:37:47 by mpankewi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCS    	= fractol.c \
			colours/red.c \
			colours/green.c \
			colours/blue.c \
			colours/rgb.c \
			fractals.c \
			utils/utils.c \
			utils/utils2.c \
			utils/utils3.c \

OBJS    	= ${SRCS:.c=.o}

GCC			= gcc -Wall -Wextra -Werror

MLX			= -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

$(NAME):	${OBJS}
			$(GCC) -o $(NAME) $(OBJS) -I /usr/local/include $(MLX)

all: $(NAME)

clean:
			rm -rf ${OBJS}

fclean:	clean
			rm -rf $(NAME)

re:				fclean all

.PHONY:         all clean fclean re