/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:07:15 by tlux              #+#    #+#             */
/*   Updated: 2018/02/04 18:22:20 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void print_ds(t_rooms **rooms)
{
	t_rooms *tmp;

	tmp = *rooms;
	while(tmp)
	{
		printf(KBLU"Room %d     :"KNRM,tmp->n);
		printf(" ds :%d | de :%d\n", tmp->ds, tmp->de);
		tmp = tmp->next;
	}
}

static int checkfords(t_rooms **rooms)
{
	t_rooms *tmp;

	tmp = *rooms;
	while(tmp)
	{
		if (tmp->ds == -1)
			return(1);
		tmp = tmp->next;
	}
	return(0);
}

void start_distance(t_rooms **rooms, int last)
{
	t_rooms *tmp;
	t_rooms *find;
	t_tubes *tmpt;
	int		i;

	i = 0;
	tmp = find_room(0, *rooms);
	tmp->ds = 0;
	tmp = find_room(last, *rooms);
	tmp->de = 0;
	while(checkfords(rooms) == 1)
	{
		tmp = *rooms;
		while(tmp)
		{
			tmpt = tmp->tubes;
			while(tmpt)
			{
				find = find_room(tmpt->n, *rooms);
				if (find->ds == i && tmp->ds == -1)
					tmp->ds = i + 1;
				if (find->de == i && tmp->de == -1)
					tmp->de = i + 1;
				tmpt = tmpt->next;
			}
			tmp = tmp->next;
		}
		i++;
	}
	print_ds(rooms);
}
