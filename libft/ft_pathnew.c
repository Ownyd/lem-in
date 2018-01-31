/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/01/31 14:39:33 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_paths	*ft_pathnew(char *p)
{
	t_paths *node;

	if (!(node = (t_paths *)malloc(sizeof(*node))))
		return (0);
	node->p = p;
	node->next = NULL;
	return (node);
}
