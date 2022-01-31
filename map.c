/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:45:37 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 09:06:42 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "prueba.h"


int main(void)
{
	t_vars vars;
	t_image image;
	t_pos pos;
	char *line;
	int fd;
	char *img;
	fd = open("map_example.ber", O_RDWR);
	line = get_next_line(fd);
	printf("%s", line);
	pos.x = 0;
	pos.y = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 2000, 2000, "So_long_bien_fresco");
	int i = 0;
	while(pos.y <= 2000 && line)
	{
		pos.x = 0;
	//	line = get_next_line(fd);
		i = 0;	
		while(pos.x <= 2000 && line)
		{
			if (line[i] == '1')
			{
			img = mlx_xpm_file_to_image(vars.mlx, "./images/tree.xpm", &image.img_width, &image.img_height);
			mlx_put_image_to_window(vars.mlx, vars.win, img, pos.x, pos.y);
			mlx_destroy_image(vars.mlx, img);
			i++;
			
			}
			
			else  if (line[i] == '0')
			{
				img = mlx_xpm_file_to_image(vars.mlx, "./images/ground.xpm", &image.img_width, &image.img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, img, pos.x, pos.y);
				mlx_destroy_image(vars.mlx, img);
				i++;

			}
			pos.x += 40;

		}
	//	pos.x = 0;
		
		line = get_next_line(fd);
		printf("%s\n", line);
		pos.y += 40;
	}



	mlx_loop(vars.mlx);

}
