# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 11:15:17 by migonzal          #+#    #+#              #
#    Updated: 2022/02/02 11:40:40 by migonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS =  ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./Libft/ft_split.c  draw_map.c main.c moves.c check.c 

OBJS = ${SRCS:.c=.o}

HDRS = so_long.h

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
