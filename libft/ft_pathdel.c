/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:07 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 16:26:49 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_pathdel(t_paths **alst)
{
	t_paths *calst;

	calst = *alst;
	while (calst)
	{
		if (calst->p)
			free(calst->p);
		free(calst);
		calst = calst->next;
	}
	*alst = NULL;
}
