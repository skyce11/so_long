/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:29:58 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 12:34:31 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"





/*
void put_image (t_map *map, int a, int b)
{
	int x;
	int y;
	int res;

	res = 40;
	x = (res * a);
	y = (res * b);
	map -> img = mlx_xpm_file_to_image(map -> mlx, "./images/tree.xpm",  &res, &res);
	mlx_put_image_to_window(map -> mlx, map -> win, map -> img, y, x);
	mlx_destroy_image(map -> mlx, map -> img);
}
*/
void get_size (t_map *map)
{
	char *line;
	int fd;
	map -> cx = 0;
	map -> cy = 0;


	fd = open("map_example.ber", O_RDWR);
	line = get_next_line(fd);

	map -> cx = strlen(line) - 1; // cambiar esto por la mia de la LIBFT
	while(line)
	{
		line = get_next_line(fd);
		map -> cy += 1;
	}
	close(fd);
	map -> tx = (map -> cx) * 40;
	map -> ty = (map -> cy) * 40;
}



void draw_map (t_map * map)
{
	char *line;
	int fd;
	int i;


	fd = open ("map_example.ber", O_RDWR);
	line = get_next_line(fd);

	while(map->y <= map -> ty && line)
	{
		map->x = 0;
		i = 0;
		while (map->x <= map -> tx && line)
		{
			if (line[i] == '1')
			{/*
				put_image(map, map -> x, map -> y);
				printf("Posición x = %d\n", map -> x);
				printf("Imagen = %s\n", map -> img);*/
				
				map->img = mlx_xpm_file_to_image (map->mlx, "./images/tree.xpm", &map -> img_width, &map -> img_height);
				mlx_put_image_to_window(map -> mlx, map -> win, map -> img, map -> x, map -> y);
				mlx_destroy_image(map -> mlx, map -> img);
				
				i++;
			}
			else if (line[i] == '0')
			{
				map -> img = mlx_xpm_file_to_image (map -> mlx, "./images/ground.xpm", &map -> img_width, &map -> img_height);
				mlx_put_image_to_window (map -> mlx, map -> win, map -> img, map -> x, map -> y);
				mlx_destroy_image (map -> mlx, map -> img);
				i++;
			}
			else if (line[i] == 'C')
			{
				map -> img = mlx_xpm_file_to_image (map -> mlx, "./images/key.xpm", &map -> img_width, &map -> img_height);
				mlx_put_image_to_window (map -> mlx, map -> win, map -> img, map -> x, map -> y);
				mlx_destroy_image (map -> mlx, map -> img);
				i++;
			}
			else if (line[i] == 'E')
			{
				map -> img = mlx_xpm_file_to_image (map -> mlx, "./images/exit.xpm", &map -> img_width, &map -> img_height);
				mlx_put_image_to_window (map -> mlx, map -> win, map -> img, map -> x, map -> y);
				mlx_destroy_image (map -> mlx, map -> img);
				i++;
			}
			else if (line[i] == 'P')
			{
				map -> img = mlx_xpm_file_to_image (map -> mlx, "./images/link.xpm", &map -> img_width, &map -> img_height);
				mlx_put_image_to_window (map -> mlx, map -> win, map -> img, map -> x, map -> y);
				mlx_destroy_image (map -> mlx, map -> img);
				map -> px = map -> x;
				map -> py = map -> y;
				i++;
			}
			map -> x += 40;
		}
		line = get_next_line(fd);
		map -> y += 40;
	}
}
