/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:07 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:16:56 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_roomdel(t_rooms **alst)
{
	t_rooms *calst;

	calst = *alst;
	while (calst)
	{
		ft_tubedel(&(calst->tubes));
		free(calst->name);
		calst->name = NULL;
		free(calst);
		calst = calst->next;
	}
	*alst = NULL;
}
