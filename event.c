/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:25:23 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/14 12:09:25 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "prueba.h"

int close(t_vars *vars)
{
	(void) vars;
	exit(0);
	return (0);
}


int main()
{
	t_vars vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (0);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (0);
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
