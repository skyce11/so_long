/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:20:38 by migonzal          #+#    #+#             */
/*   Updated: 2022/02/02 11:20:34 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./gnl/get_next_line.h"
# include "./Libft/libft.h"

typedef struct s_map
{
	char ** map;
	int x;
	int y;
	int px;
	int py;
	int mov;
	int cx;
	int tx;
	int cy;
	int ty;
	void *mlx;
	void *win;
	void *img;
	int img_height;
	int img_width;
}			t_map;


void freemap(t_map *map);
void ft_error(char *str, int c, t_map *map);
void parser (int argc, char const **argv, t_map *map);
void initiator(t_map *map);
void get_size(int fd, t_map *map);
char **mountmap(int fd, t_map *map);
void put_image(t_map *map, int a, int b, char *imgname);
void draw_map (t_map *map);
int moves(int keycode, t_map *map);
int move_right(t_map *map);
int move_left(t_map *map);
int move_up(t_map *map);
int move_down(t_map *map);
# endif
