/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:06:38 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/25 10:27:44 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRUEBA_H
# define PRUEBA_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include "./gnl/get_next_line.h"
/*
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}			t_data;

*/


typedef struct s_pos
{
	int x;
	int y;
}			t_pos;


typedef struct s_vars
{
	void *mlx;
	void *win;
}			t_vars;


typedef struct s_image
{
	void *img;
	char *relative_path;
	char *addr;
	int bits_per_pixel;
	int img_width;
	int img_height;
}			t_image;


//void charge_img(t_vars vars, t_image image);
int key_hook(int keycode, t_vars *vars, t_image *image, t_pos pos);


#endif
