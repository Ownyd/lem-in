/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:30:49 by tlux              #+#    #+#             */
/*   Updated: 2018/01/30 13:47:21 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rooms	*find_room_by_name(char *name, t_rooms *lst)
{
	t_rooms *tmp;
	tmp = lst;

	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return(tmp);
		tmp = tmp->next;
	}
	return (0);
}
