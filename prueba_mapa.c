/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_mapa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:27:41 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 12:38:14 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


int main ()
{
	char *line;
	int fd;
	int i;
	int j;
	int c;

	fd = open("map_example.ber", O_RDWR);
	line = get_next_line(fd);
	i = 0;
	j = 0;
	c = 0;

	c = strlen(line) - 1;
	printf(" Esto son las x =%d\n", c);

	while (line)
	{
		line = get_next_line(fd);
		i++;
	}


	printf("Esto son las y = %d\n", i);



	return (0);

	



}

