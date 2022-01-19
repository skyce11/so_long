/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:31:39 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/19 12:35:04 by migonzal         ###   ########.fr       */
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



int key_hook(int keycode, t_vars *vars, t_image *image)
{
	char * win;
	char *img;
	
	win = vars -> win;
	

	if (keycode == 53)
		exit(0);
	if (keycode == 36)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./test.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, 0, 0);
		mlx_destroy_image(vars -> mlx, img);
	}
	if (keycode == 5)
	{
		img = mlx_xpm_file_to_image(vars -> mlx, "./ground.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars, win, img, 0, 0);
		mlx_destroy_image(vars -> mlx, img);
		img = mlx_xpm_file_to_image(vars -> mlx, "./test_right.xpm", &image -> img_width, &image -> img_height);
		mlx_put_image_to_window(vars -> mlx, win, img, 10, 0);
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
	int x = -1;
	int y = -1;

	//int img_width;
	//int img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "WIP");
	while (x <= 1920)
	{
		while (y <= 1080)
		{
			img = mlx_xpm_file_to_image(vars.mlx, "./ground.xpm", &image.img_width, &image.img_height);
			mlx_put_image_to_window(vars.mlx, vars.win, img, x, ++y);
			mlx_destroy_image(vars.mlx, img);
		}
		img = mlx_xpm_file_to_image(vars.mlx, "./ground.xpm", &image.img_width, &image.img_height);
		mlx_put_image_to_window(vars.mlx, vars.win, img, ++x, y);
		mlx_destroy_image(vars.mlx, img);

	}
//	image.img = mlx_xpm_file_to_image(vars.mlx, image.relative_path, &image.img_width, &image.img_height);
//	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 5, 5);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);


}
