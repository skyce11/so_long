/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:05:39 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/14 14:05:28 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	last_error(t_map *map)
{
	int	i;
	int	j;
	int	c;
	int	p;

	i = -1;
	c = 0;
	p = 0;
	while (p <= map -> cx -1)
	{
		if (map -> map[0][p] != '\0')
			p++;
	}
	while (++i <= map -> cy -1)
	{
		j = -1;
		c = 0;
		while (++j <= map -> cx)
		{
			if (map -> map[i][j] != '\0')
				c++;
		}
		if (p != c)
			ft_error("Error\n Último error de los huevos", 1, map);
	}
}
