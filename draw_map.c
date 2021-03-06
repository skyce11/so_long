/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:24:57 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/14 13:25:54 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiator(t_map *map)
{
	map->map = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map -> cc = 0;
	map->x = 0;
	map->y = 0;
	map->px = 0;
	map->py = 0;
	map -> mov = 0;
	map -> cx = 0;
	map -> tx = 0;
	map -> cy = 0;
	map -> ty = 0;
}

void	parser(int argc, char const **argv, t_map *map)
{
	int	fd;

	if (argc < 2)
		ft_error("Error\n Only one argc man", 0, map);
	else if (argc > 2)
		ft_error("Error\n Too much argc man", 0, map);
	checkber(argv[1], map);
	fd = open (argv[1], O_RDONLY);
	map -> map = mountmap(fd, map);
	close (fd);
}
/*
char	**mountmap(int fd, t_map *map)
{
	char	**ls;
	char	*spliter;
	char	*line;
	char	*tmp;

	spliter = ft_calloc(sizeof(char), 1);
	line = get_next_line (fd);
	map -> cx = ft_strlen(line) - 1;
	map -> tx = (map -> cx) * 40;
	while (line != NULL)
	{
		map -> y += 1;
		tmp = ft_strdup(spliter);
		free(spliter);
		spliter = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	map -> cy = map -> y;
	map -> ty = (map -> cy) * 40;
	ls = ft_split(spliter, '\n');
	free(spliter);
	return (ls);
}
*/

char	**mountmap(int fd, t_map *map)
{
	char	*spliter;
	char	*aux;
	char	**ls;
	char	*tmp;

	spliter = ft_calloc(sizeof(char), 1);
	aux = get_next_line(fd);
	map -> cx = ft_strlen(aux) -1;
	map -> tx = (map -> cx) * 40;
	while (aux != NULL)
	{
		map->y += 1;
		tmp = ft_strdup(spliter);
		free(spliter);
		spliter = ft_strjoin(tmp, aux);
		free(aux);
		aux = get_next_line(fd);
	}
	map -> cy = map -> y;
	map -> ty = (map -> cy) * 40;
	ls = ft_split(spliter, '\n');
	free(spliter);
	return (ls);
}

void	put_image(t_map *map, int a, int b, char *imgname)
{
	int		x;
	int		y;
	int		res;
	void	*img;

	res = 40;
	x = (res * a);
	y = (res * b);
	img = mlx_xpm_file_to_image(map->mlx, imgname, &res, &res);
	mlx_put_image_to_window(map->mlx, map->win, img, y, x);
	mlx_destroy_image(map->mlx, img);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= map -> cy - 1)
	{
		j = -1;
		while (++j <= map -> cx)
		{
			if (map -> map[i][j] == '1')
				put_image(map, i, j, "./images/tree.xpm");
			if (map -> map[i][j] == '0')
				put_image(map, i, j, "./images/ground.xpm");
			if (map -> map[i][j] == 'C')
				put_image (map, i, j, "./images/key.xpm");
			if (map -> map[i][j] == 'E')
				put_image(map, i, j, "./images/exit.xpm");
			if (map -> map[i][j] == 'P')
			{
				put_image (map, i, j, "./images/link.xpm");
				map -> px = i;
				map -> py = j;
			}
		}
	}
}
