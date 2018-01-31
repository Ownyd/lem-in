/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:02:22 by tlux              #+#    #+#             */
/*   Updated: 2018/01/31 14:50:52 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int print_paths(t_paths **paths)
{
	t_paths *tmp;

	tmp = *paths;
	while (tmp)
	{
	//	write(1, "debug\n",6);
		printf("%s\n",(char *)tmp->p);
		tmp = tmp->next;
	}
	return (0);
}

void find_paths(t_rooms *rooms, int last)
{
	t_rooms *tmp;
	t_paths *paths;

	paths = NULL;
	tmp = find_room(0, rooms);
	while(tmp->tubes)
	{
		ft_pathadd(&paths, ft_pathnew(ft_strjoin("0", ft_itoa(tmp->tubes->n))));
		tmp->tubes = tmp->tubes->next;
	}
	print_paths(&paths);
}
