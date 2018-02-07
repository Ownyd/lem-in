/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:56:48 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 21:57:59 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		stop_parse(int c)
{
	static int stop = 0;

	if (c == 1)
		stop = 1;
	if (stop == 1)
		return (1);
	else
		return (0);
}

int		duplicate_name(char *str, t_rooms *rooms)
{
	t_rooms *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->name && str)
			if (ft_strcmp(tmp->name, str) == 0)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		non_tube(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || ft_strchr(str, '-') == 0)
		return (1);
	while (str[i] != '-' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (1);
	i++;
	while (str[i] != '-' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}
