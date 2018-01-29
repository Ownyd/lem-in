/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/01/29 11:12:51 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_tubes	*ft_tubenew(int number)
{
	t_tubes *node;

	node = (t_tubes *)malloc(sizeof(*node));
	if (node == NULL)
		return (0);
	node->n = number;
	node->next = NULL;
	return (node);
}
