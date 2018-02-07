/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:59:46 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 22:19:08 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	add_room(t_rooms **rooms, char *line, int number, char *act)
{
	char **split;
	long coord_x;
	long coord_y;

	split = ft_strsplit(line, "\t ");
	if ((!split[0] || !split[1] || !split[2]) && stop_parse(1) >= 0)
		return ;
	coord_x = ft_atoll(split[1]);
	coord_y = ft_atoll(split[2]);
	if (ft_strchr(split[0], '-') != 0 || !ft_isstrdigit(split[1])
		|| !ft_isstrdigit(split[2]) || split[3] != NULL || split[0][0] == 'L'
		|| duplicate_name(split[0], *rooms) == 1
		|| coord_x == A_R || coord_y == A_R)
	{
		stop_parse(1);
		return ;
	}
	ft_roomadd(rooms, ft_roomnew(split[0], coord_x, coord_y, number));
	if (ft_strcmp(act, "start") == 0)
		(*rooms)->start = 1;
	if (ft_strcmp(act, "end") == 0)
		(*rooms)->end = 1;
	ft_tabfree(split);
}

void	add_tube(t_rooms **rooms, char *line)
{
	char	**split;
	t_rooms	*tmp1;
	t_rooms	*tmp2;

	tubemode(1);
	if (non_tube(line) && stop_parse(1) >= 0)
		return ;
	split = ft_strsplit(line, "- ");
	if ((!split[0] || !split[1]) && stop_parse(1) >= 0)
		return ;
	tmp1 = find_room_by_name(split[0], *rooms);
	tmp2 = find_room_by_name(split[1], *rooms);
	if (tmp1 == NULL || tmp2 == NULL || split[2] != NULL
			|| ft_strcmp(split[0], split[1]) == 0)
	{
		stop_parse(1);
		return ;
	}
	ft_tubeadd(&(tmp1->tubes), ft_tubenew(tmp2->n));
	ft_tubeadd(&(tmp2->tubes), ft_tubenew(tmp1->n));
	ft_tabfree(split);
}
