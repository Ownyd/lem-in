/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:30:49 by tlux              #+#    #+#             */
/*   Updated: 2018/02/06 19:14:01 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rooms	*find_room_extrems(char *search, t_rooms *lst)
{
	t_rooms *tmp;
	tmp = lst;

	while (tmp)
	{
		if (ft_strcmp(search, "start") == 0)
			if (tmp->start == 1)
				return(tmp);
		if (ft_strcmp(search, "end") == 0)
			if (tmp->end == 1)
				return(tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
