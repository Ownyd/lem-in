/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:37:00 by tlux              #+#    #+#             */
/*   Updated: 2018/02/08 00:04:11 by tlux             ###   ########.fr       */
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
			printf("L%d-%s ", tmp2->ant, (*tmp)->name);
			if ((*tmp)->n != find_room_extrems("end", rooms)->n)
				(*tmp)->ant = tmp2->ant;
			else
				(*tmp)->ant++;
			tmp2->ant = -1;
		}
		sp_path--;
		*tmp = find_room(ft_atoi(*sp_path), rooms);
	}
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
		printf("L%d-%s ", ants - *todrag + 1, tmp->name);
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
		printf("\n");
		tmp = paths;
	}
}
