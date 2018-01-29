/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/01/29 10:15:54 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_rooms	*ft_roomnew(char *name, int coord_x, int coord_y, int number)
{
	t_rooms *node;

	if (!(node = (t_rooms *)malloc(sizeof(*node))))
		return (0);
	node->name = name;
	node->n = number;
	node->x = coord_x;
	node->y = coord_y;
	node->tubes = NULL;
	node->next = NULL;
	return (node);
}
