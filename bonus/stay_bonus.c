/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stay.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:16:35 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/07 12:20:01 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	stay_right(t_map *map)
{
	put_image(map, map->px, map->py, "./images/link_right.xpm");
	return (0);
}

int	stay_left(t_map *map)
{
	put_image(map, map->px, map->py, "./images/link_left.xpm");
	return (0);
}

int	stay_down(t_map *map)
{
	put_image(map, map->px, map->py, "./images/link.xpm");
	return (0);
}

int	stay_up(t_map *map)
{
	put_image(map, map->px, map->py, "./images/link_up.xpm");
	return (0);
}

void	checkber(char const *extension, t_map *map)
{
	char	*ber;
	char	*aux;
	int		len;
	int		i;

	i = -1;
	ber = ".ber";
	len = ft_strlen((char *)extension);
	while (extension[len] != '.')
	{
		len--;
	}
	aux = ft_substr((char *)extension, len, ft_strlen((char *)extension));
	while (++i < 4)
	{
		if (aux[i] != ber[i])
		{
			free(aux);
			ft_error("Error\n This isnt a .ber man", 0, map);
		}
	}
	free(aux);
}
