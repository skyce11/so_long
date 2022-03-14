/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:20:38 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/08 09:07:36 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include "../Libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		cc;
	int		x;
	int		y;
	int		px;
	int		py;
	int		mov;
	int		cx;
	int		tx;
	int		cy;
	int		ty;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_height;
	int		img_width;
	char	*movs;
}			t_map;

int		closewin(t_map *map);
void	freemap(t_map *map);
void	ft_error(char *str, int c, t_map *map);
void	all_ok(t_map *map);
void	all_true(t_map *map);
void	only_five(t_map *map);
void	border(t_map *map);
void	parser(int argc, char const **argv, t_map *map);
void	checkber(char const *extension, t_map *map);
void	initiator(t_map *map);
void	get_size(int fd, t_map *map);
char	**mountmap(int fd, t_map *map);
void	put_image(t_map *map, int a, int b, char *imgname);
void	draw_map(t_map *map);
int		moves(int keycode, t_map *map);
int		stay_right(t_map *map);
int		stay_left(t_map *map);
int		stay_down(t_map *map);
int		stay_up(t_map *map);
void	aux_right(t_map *map);
void	aux_left(t_map *map);
void	aux_up(t_map *map);
void	aux_down(t_map *map);
int		move_right(t_map *map);
int		move_left(t_map *map);
int		move_up(t_map *map);
int		move_down(t_map *map);

#endif
