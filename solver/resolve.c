/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:37:00 by tlux              #+#    #+#             */
/*   Updated: 2018/02/08 21:51:11 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void		progress_ants(t_rooms *rooms, char **sp_path, t_rooms **tmp)
{
	t_rooms	*tmp2;

	while ((*tmp)->ds != 1)
	{
		tmp2 = find_room(ft_atoi(*(sp_path - 1)), rooms);
		if (tmp2->ant != -1)
		{
			ft_putchar('L');
			ft_putnbr(tmp2->ant);
			ft_putchar('-');
			ft_putstr((*tmp)->name);
			ft_putchar(' ');
			if ((*tmp)->n != find_room_extrems("end", rooms)->n)
				(*tmp)->ant = tmp2->ant;
			else
				(*tmp)->ant++;
			tmp2->ant = -1;
		}
		sp_path--;
		*tmp = find_room(ft_atoi(*sp_path), rooms);
	}
	ft_tabfree(sp_path);
}

static void		progress_path(char *path, t_rooms *rooms, int *todrag, int ants)
{
	char	**sp_path;
	t_rooms	*tmp;

	sp_path = ft_strsplit(path, " ");
	while (*sp_path)
		sp_path++;
	sp_path--;
	tmp = find_room(ft_atoi(*sp_path), rooms);
	progress_ants(rooms, sp_path, &tmp);
	if ((tmp->ant == -1 && *todrag != 0) ||
			(tmp->n == find_room_extrems("end", rooms)->n && *todrag >= 0))
	{
		if (tmp->n != find_room_extrems("end", rooms)->n)
			tmp->ant = ants - *todrag + 1;
		else
			(tmp->ant)++;
		ft_putchar('L');
		ft_putnbr(ants - *todrag + 1);
		ft_putchar('-');
		ft_putstr(tmp->name);
		ft_putchar(' ');
		(*todrag)--;
	}
}

void			resolve(t_paths *paths, t_rooms *rooms, int ants)
{
	int		todrag;
	t_paths	*tmp;

	tmp = paths;
	todrag = ants;
	while (find_room_extrems("end", rooms)->ant < ants - 1)
	{
		while (tmp)
		{
			if (tmp->p != NULL)
			{
				progress_path(tmp->p, rooms, &todrag, ants);
			}
			tmp = tmp->next;
		}
		write(1, "\n", 1);
		tmp = paths;
	}
}
