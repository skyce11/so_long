/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:44:53 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/19 12:29:21 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "prueba.h"




int close()
{
	exit(0);
	return (0);
}




void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char * dst;

	dst = data -> addr + (y * data ->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
//	t_vars vars;
	int c = 5;
	int c1 = 5;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hellow world");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr =   mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (c <=100)
		my_mlx_pixel_put(&img, c++, 5, 0x0FF0000);
	c = 5;
	while (c <=100)
		my_mlx_pixel_put(&img, 5, c++, 0x0FF0000);
	c = 5;
	while (c1 <= 100)
		my_mlx_pixel_put(&img, c++, c1++, 0x00000FF);
	while (c >= 5)
		my_mlx_pixel_put(&img, c--, 100, 0x0FF0000);
	while (c1 >= 5)
		my_mlx_pixel_put(&img, 100, c1--, 0x0FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L<<0, close, &img);
	mlx_loop(mlx);
}




