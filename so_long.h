/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:08:29 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 11:36:02 by migonzal         ###   ########.fr       */
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


	char **map;
	int mov;
	int x;
	int y;
	int px;
	int py;
	int cx;
	int cy;
	int tx;
	int ty;
	void *mlx;
	void *win;
	void *img;   // aqui debajo no pong na
	int img_height;
	int img_width;
}			t_map;


/*

typedef struct s_image
{
	void *img;
	char *path;
	char *addr;
	int bits_per_pixel;
	int img_width;
	int img_height;
}			t_image;
*/
/*
int moves(int keycode, t_map *map);
int move_right(t_map *map);
int move_left(t_map *map);
int move_up(t_map *map);
int move_down(t_map *map);
//void put_image(t_map *map, int a, int b);
void get_size(t_map *map);
void draw_map (t_map* map);
*/

void get_size (t_map *map);
void put_array (t_map *map);
void recorre_prueba(t_map *map);



#endif
