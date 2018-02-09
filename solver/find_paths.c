/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:02:22 by tlux              #+#    #+#             */
/*   Updated: 2018/02/08 21:09:34 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int		store_used(int n, char *act)
{
	static t_tubes	*used = NULL;
	t_tubes			*tmp;

	tmp = used;
	if (ft_strcmp(act, "add") == 0)
		ft_tubeadd(&used, ft_tubenew(n));
	else if (ft_strcmp(act, "read") == 0)
	{
		while (tmp)
		{
			if (tmp->n == n)
				return (1);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_tubedel(&used);
	}
	return (0);
}

static int		nullize_path(char **path)
{
	free(*path);
	*path = NULL;
	return (1);
}

static int		find_neighbour(t_tubes *tmpt, t_rooms *rooms, int *de_min)
{
	t_rooms *tmp;

	tmp = find_room(tmpt->n, rooms);
	if ((*de_min == -1 || tmp->de < *de_min) &&
			store_used(tmp->n, "read") == 0)
		if (tmp->de != -1)
			*de_min = tmp->de;
	return (1);
}

static void		travel_path(t_rooms *act, t_rooms *rooms, t_paths *paths)
{
	int		de_min;
	t_rooms	*tmp;
	t_tubes	*tmpt;

	de_min = -1;
	tmpt = act->tubes;
	while (tmpt && find_neighbour(tmpt, rooms, &de_min))
		tmpt = tmpt->next;
	if ((tmpt = act->tubes) && de_min == -1 && nullize_path(&(paths->p)))
		return ;
	while (tmpt)
	{
		tmp = find_room(tmpt->n, rooms);
		if (tmp->de == de_min && store_used(tmp->n, "read") == 0)
			break ;
		tmpt = tmpt->next;
	}
	if (!tmpt && nullize_path(&(paths->p)))
		return ;
	paths->p = ft_strfreejoin(paths->p, " ", 1);
	paths->p = ft_strfreejoin(paths->p, ft_itoa(tmp->n), 3);
	if ((paths->len)++ && tmp->n != find_room_extrems("end", rooms)->n)
		store_used(tmp->n, "add");
	if (tmp->n != find_room_extrems("end", rooms)->n)
		travel_path(tmp, rooms, paths);
}

t_paths			*find_paths(t_rooms *rooms)
{
	t_rooms	*tmp;
	t_paths	*paths;
	t_tubes *tmpt;

	paths = NULL;
	tmp = find_room_extrems("start", rooms);
	store_used(tmp->n, "add");
	tmpt = tmp->tubes;
	while (tmpt)
	{
		if (store_used(tmpt->n, "read") == 0)
		{
			store_used(tmpt->n, "add");
			ft_pathadd(&paths, ft_pathnew(ft_itoa(tmpt->n)));
			paths->len = 2;
			if (tmpt->n != find_room_extrems("end", rooms)->n)
				travel_path(find_room(tmpt->n, rooms), rooms, paths);
		}
		tmpt = tmpt->next;
	}
	store_used(0, "free");
	return (paths);
}
