/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:30:49 by tlux              #+#    #+#             */
/*   Updated: 2018/01/29 11:32:47 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rooms	*find_room(int number, t_rooms *lst)
{
	t_rooms *tmp;
	tmp = lst;

	while (tmp)
	{
		if (tmp->n == number)
			return(tmp);
		tmp = tmp->next;
	}
	return (0);
}
