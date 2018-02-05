/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:02:22 by tlux              #+#    #+#             */
/*   Updated: 2018/02/05 14:57:30 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int print_paths(t_paths **paths)
{
	t_paths *tmp;

	tmp = *paths;
	while (tmp)
	{
		if (tmp->p != NULL)
		printf(KYEL"%s\n"KNRM,(char *)tmp->p);
		tmp = tmp->next;
	}
	return (0);
}

static int	store_used(int n, char *act)
{
	static t_tubes *used;
	t_tubes *tmp;

	tmp = used;
	if (ft_strcmp(act, "add") == 0)
		ft_tubeadd(&used, ft_tubenew(n));
	if (ft_strcmp(act, "read") == 0)
	{
		while (tmp)
		{
			if (tmp->n == n)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}
static void travel_path(t_rooms *act, t_rooms *rooms, t_paths *paths, int last)
{
	int de_min;
	t_rooms *tmp;
	t_tubes *tmpt;
	de_min = -1;
	tmpt = act->tubes;
	printf(KGRN"%d -> "KNRM,act->n);
	while(tmpt)
	{
		tmp = find_room(tmpt->n, rooms);
		printf(KRED"%d "KNRM,tmp->n);
		if ((de_min == -1 || tmp->de < de_min) && store_used(tmp->n, "read") == 0)
			de_min = tmp->de;
		tmpt = tmpt->next;
	}
	printf("\n");
	if(de_min == -1)
	{
		printf("Empty path\n");
		paths->p = NULL;
		return ;
	}
	tmpt = act->tubes;
	while(tmpt)
	{
		tmp = find_room(tmpt->n, rooms);
		if(tmp->de == de_min && store_used(tmp->n, "read") == 0)
			break;
		tmpt = tmpt->next;
	}
	paths->p = ft_strjoin(paths->p, ft_itoa(tmp->n));
		paths->p = ft_strjoin(paths->p, " ");
	if (tmp->n != last)
		store_used(tmp->n, "add");
	printf("room chosen :%d (%d)\n",tmp->n, de_min);
	if (tmp->n != last)
		travel_path(tmp, rooms, paths, last);
}

void find_paths(t_rooms *rooms, int last)
{
	t_rooms *tmp;
	t_paths *paths;

	paths = NULL;
	tmp = find_room(0, rooms);
	store_used(tmp->n, "add");
	while(tmp->tubes)
	{
		printf(KMAG"NEW PATH --- :\n"KNRM);
		store_used(tmp->tubes->n, "add");
		ft_pathadd(&paths, ft_pathnew(ft_strjoin("0 ", ft_itoa(tmp->tubes->n))));
		paths->p = ft_strjoin(paths->p, " ");
		travel_path(find_room(tmp->tubes->n, rooms), rooms, paths, last);
		tmp->tubes = tmp->tubes->next;
	}
	printf(KMAG"\nPATHS :\n"KNRM);
	print_paths(&paths);
}
