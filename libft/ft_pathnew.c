/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 16:48:15 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_paths	*ft_pathnew(char *p)
{
	t_paths *node;

	if (!(node = (t_paths *)malloc(sizeof(*node))))
		return (0);
	node->p = ft_strdup(p);
	node->len = 0;
	node->next = NULL;
	free(p);
	return (node);
}
