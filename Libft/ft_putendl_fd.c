/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:36:21 by migonzal          #+#    #+#             */
/*   Updated: 2021/09/29 09:41:05 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	a;

	a = '\n';
	i = -1;
	while (s && s[++i])
	{
		write(fd, &s[i], 1);
	}
	write(fd, &a, 1);
}
