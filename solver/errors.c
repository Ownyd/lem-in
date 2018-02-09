/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:56:48 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:14:47 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	err_msg(int err)
{
	if (err == 0)
		ft_putendl_fd("Room declared after tube", 2);
	else if (err == 1)
		ft_putendl_fd("Invalid room/coordonates arguments", 2);
	else if (err == 2)
		ft_putendl_fd("Invalid room/coordonates format or duplicate room", 2);
	else if (err == 3)
		ft_putendl_fd("Invalid tube format", 2);
	else if (err == 4)
		ft_putendl_fd("Invalid tube arguments", 2);
	else if (err == 5)
		ft_putendl_fd("Invalid rooms names in the tube", 2);
}

int			stop_parse(int c, int err)
{
	static int stop = 0;

	if (c == 1)
		stop = 1;
	if (stop == 1)
	{
		err_msg(err);
		return (1);
	}
	else
		return (0);
}

int			duplicate_name(char *str, t_rooms *rooms)
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

int			non_tube(char *str)
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
