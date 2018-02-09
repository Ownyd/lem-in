/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:07 by tlux              #+#    #+#             */
/*   Updated: 2018/02/08 16:53:38 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tubedel(t_tubes **alst)
{
	t_tubes *calst;

	calst = *alst;
	while (calst)
	{
		calst->n = 0;
		free(calst);
		calst = calst->next;
	}
	*alst = NULL;
}
