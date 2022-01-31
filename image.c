/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:31:39 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/25 10:44:30 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"


/*
void charge_img(t_vars vars, t_image image )
{
	(void) vars;
	(void) image;
}
*/



int key_hook(int keycode, t_vars *vars, t_image *image, t_pos pos)
{
	char * win;
	char *img;
	pos.x = 0;
	pos.y = 0;

	
	win = vars -> win;
	

	if (keycode == 53)
		exit(0);
	else if (keycode == 36)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/link.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
	}
	else if (keycode == 124)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/ground.xpm", 
				&image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
		pos.x += 40;
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/link_right.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
	}
	else if (keycode == 123)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/ground.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
		pos.x -= 40;
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/link_left.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
	}
	else if (keycode == 126)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/ground.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
		pos.y -= 40;
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/link_up.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
	}
	else if (keycode == 125)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/ground.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
		pos.y += 40;
		img = mlx_xpm_file_to_image(vars -> mlx, "./images/link.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, pos.x, pos.y);
		mlx_destroy_image(vars -> mlx, img);
	}
	else
	{
		printf("%i\n", keycode);
	}
	return (0);

}


int main()
{
	t_vars vars;

//	t_data image;
	t_image image;
	char *img;
//	image.relative_path = "./test.xpm";
	//void *img;
	//char *relative_path = "./test.xpm";
	int x = 0;
	int y = 0;

	//int img_width;
	//int img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "WIP");
	while (x <= 500)
	{
			y = 0;
		while (y <= 500)
		{
			img = mlx_xpm_file_to_image(vars.mlx, "./images/ground.xpm", &image.img_width, &image.img_height);
			mlx_put_image_to_window(vars.mlx, vars.win, img, x, y);
			mlx_destroy_image(vars.mlx, img);
			y += 10;
		}
		x += 10;
	}
//	image.img = mlx_xpm_file_to_image(vars.mlx, image.relative_path, &image.img_width, &image.img_height);
//	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 5, 5);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);


}
