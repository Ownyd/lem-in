/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:07 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 16:31:16 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_roomdel(t_rooms **alst)
{
	t_rooms *calst;
	t_tubes *tmpt;

	calst = *alst;
	while (calst)
	{	
		tmpt = calst->tubes;
		while (tmpt)
		{
			if (tmpt)
				free(tmpt);
			tmpt = tmpt->next;
		}
		if (calst->name)
			free(calst->name);
		free(calst);
		calst = calst->next;
	}
	*alst = NULL;
}
