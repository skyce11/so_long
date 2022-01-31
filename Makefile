# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 09:56:15 by migonzal          #+#    #+#              #
#    Updated: 2022/01/31 12:42:06 by migonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  array.c  ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./Libft/ft_split.c

OBJS = ${SRCS:.c=.o}

HDRS = so_long.h 

NAME = mlx.a

cc = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME) -g -fsanitize=address

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


