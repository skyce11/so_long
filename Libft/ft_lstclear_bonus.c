/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:33:02 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/10 08:56:55 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*t;
	t_list	*aux;

	t = *lst;
	while (t)
	{
		aux = t -> next;
		ft_lstdelone(t, del);
		t = aux;
	}
	*lst = NULL;
}
