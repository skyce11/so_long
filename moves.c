/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   B: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:32:32 b migonzal          #+#    #+#             */
/*   Updated: 2022/01/27 09:46:04 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"



int move_right (t_map *map)
{
//	if (kecode == 124)
//	{
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/ground.xpm", 
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map ->win,
				map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
		map -> px+= 40;
		map -> mov += 1;
		printf("El número actúal de movimientos es: %d\n", map -> mov);
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/link_right.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
//	}
	return (0);
}


int move_left (t_map *map)
{
//	if (kecode == 123)
//	{
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/ground.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
		map -> px -= 40;
		map -> mov += 1;
		printf("El número actúal de movimientos es: %d\n", map -> mov);
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/link_left.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px,  map  -> py );
		mlx_destroy_image(map -> mlx, map -> img);
//	}
	return (0);
}

int move_up (t_map *map)
{
//	if (kecode == 126)
//	{
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/ground.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
		map -> py -= 40;
		map -> mov += 1;
		printf("El número actúal de movimientos es: %d\n", map -> mov);
		map -> img  = mlx_xpm_file_to_image(map -> mlx, "./images/link_up.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
//	}
	return (0);
}


int move_down(t_map *map)
{
//	if (kecode == 125)
//	{
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/ground.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px, map -> py );
		mlx_destroy_image(map -> mlx, map -> img);
		map -> py+= 40;
		map -> mov += 1;
		printf("El número actúal de movimientos es: %d\n", map -> mov);
		map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/link.xpm",
				&map -> img_width, &map -> img_height);
		mlx_put_image_to_window(map -> mlx, map -> win,
				map -> img, map -> px, map -> py);
		mlx_destroy_image (map -> mlx, map -> img);
//	}
	return (0);
}

int moves (int keycode, t_map *map)
{

	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		move_right(map);
	if (keycode == 123)
		move_left(map);
	if (keycode == 126)
		move_up(map);
	if (keycode == 125)
		move_down(map);

	return (0);

}
