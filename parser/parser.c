/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:34:06 by tlux              #+#    #+#             */
/*   Updated: 2018/01/30 17:01:32 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void add_room(t_rooms **rooms, char *line, int number)
{
	char **split;
	int coord_x;
	int coord_y;
	split = ft_strsplit(line, ' ');
	coord_x = ft_atoi(split[1]);
	coord_y = ft_atoi(split[2]);
	ft_roomadd(rooms, ft_roomnew(split[0], coord_x, coord_y, number));
}

void add_tube(t_rooms **rooms, char *line)
{
	char **split;
	t_rooms *tmp1;
	t_rooms *tmp2;
	split = ft_strsplit(line, '-');
	tmp1 = find_room_by_name(split[0], *rooms);
	tmp2 = find_room_by_name(split[1], *rooms);
	ft_tubeadd(&(tmp1->tubes), ft_tubenew(tmp2->n));
	ft_tubeadd(&(tmp2->tubes), ft_tubenew(tmp1->n));
	printf(KMAG"New tube   : ");
	printf(KNRM"%d <-> %d\n",tmp1->n, tmp2->n);
}

int	parser(int ants)
{
	char *line;
	t_rooms *rooms;
	int end;
	int i;

	i = -1;
	end = 0;
	if (get_next_line(0, &line) <= 0)
		return(printf(KRED"No file / Empty file"KNRM));
	if (ft_strcmp(line, "##start") != 0)
		return(printf(KRED"No start instruction"KNRM));
	while(get_next_line(0, &line) == 1)
	{
		if (end <= 1 && line[0] != '#' && ++i >= 0)
		{
			add_room(&rooms, line, i);
			printf(KGRN"New room   : "KNRM);
			printf("\"%s\" - ",rooms->name);
			printf("[%d].[%d] - ", rooms->x, rooms->y);
			printf("N.%d\n", rooms->n);
		}
		if (end == 2 && line[0] != '#')
			add_tube(&rooms, line);
		end = end >= 1 ? 2 : 0;
		if (line[0] == '#' && ft_strcmp(line, "##end") == 0)
			end = 1;
	}
	find_paths(rooms, i);
	return(0);
}

int	main(void)
{
	char *line;
	int ants;
	
	get_next_line(0, &line);
	ants = ft_atoi(line);
	printf(KYEL"Ants count : "KNRM);
	printf("%d\n", ants);
	parser(ants);
	return(0);
}
