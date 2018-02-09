/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:07:15 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:10:25 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	explore_tubes(t_rooms **rooms, t_rooms *tmp, int i)
{
	t_tubes *tmpt;
	t_rooms *find;

	tmpt = tmp->tubes;
	while (tmpt)
	{
		find = find_room(tmpt->n, *rooms);
		if (find->ds == i && tmp->ds == -1)
			tmp->ds = i + 1;
		if (find->de == i && tmp->de == -1)
			tmp->de = i + 1;
		tmpt = tmpt->next;
	}
}

int			start_distance(t_rooms **rooms)
{
	t_rooms *tmp;
	int		i;
	int		c;

	i = 0;
	c = -1;
	if (!(tmp = find_room_extrems("start", *rooms)))
		return (0);
	tmp->ds = 0;
	if (!(tmp = find_room_extrems("end", *rooms)))
		return (0);
	tmp->de = 0;
	while (++c <= MAXPATH / 2)
	{
		tmp = *rooms;
		while (tmp)
		{
			explore_tubes(rooms, tmp, i);
			tmp = tmp->next;
		}
		i++;
	}
	return (find_room_extrems("start", *rooms)->de == -1 ? 0 : 1);
}
