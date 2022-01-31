/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:06:49 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 12:57:53 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"


void get_size (t_map *map)
{
	char *line;
	int fd;
	map -> cx = 0;
	map -> cy = 0;

	fd = open ("map_example.ber", O_RDWR);
	line = get_next_line(fd);

	map -> cy = strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		map -> cx += 1;
	}
	close (fd);
}


void put_array (t_map *map)
{
	int fd;
	map -> y = 0;

	fd = open ("map_example.ber", O_RDWR);
	char *spliter;
	char *line;
	char *tmp;

	spliter = calloc (sizeof(char), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		//map -> y += 1;
		tmp = strdup(spliter);
		free(spliter);
		spliter = ft_strjoin(tmp, line);
		//free(tmp);
		//free(line);
		printf("esto es spliter :\n%s\n", spliter);
		line = get_next_line(fd);
	}

	map -> map = ft_split (spliter, '\n');
	free(spliter);
	printf("A ver que ahy aqui : %c\n", map -> map[1][4]);
}



void recorre_prueba (t_map *map)
{
	int x;
	int y;
	x = 0;
	y = 0;
	printf("Esto es cx: %d\n", map -> cx);
	printf("Esto es cy:%d\n", map -> cy);
	while (x < 9)
	{
		y = 0;
		while (y < 11)
		{
			printf("%c\n", map -> map[x][y]);
			y++;
		}
		x++;
	}
}

int main()
{
	t_map map;

	get_size(&map);
	printf(" El tamaño de x es : %d\n", map.cx);
	printf(" El tamaño de y es : %d\n", map.cy);
	put_array(&map);
	printf("Prueba de posición: %c\n", map.map[1][4]);
	recorre_prueba(&map);
	return (0);
}
