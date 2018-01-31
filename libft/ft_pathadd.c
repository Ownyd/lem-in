/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:56 by tlux              #+#    #+#             */
/*   Updated: 2018/01/31 14:38:32 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pathadd(t_paths **alst, t_paths *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}