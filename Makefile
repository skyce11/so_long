# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 09:56:15 by migonzal          #+#    #+#              #
#    Updated: 2022/01/19 11:55:33 by migonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = image.c

OBJS = ${SRCS:.c=.o}

HDRS = prueba.h

NAME = mlx.a

cc = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


