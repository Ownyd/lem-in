/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:34:06 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:27:05 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		tubemode(int n)
{
	static int mode = 0;

	if (n == 1)
		mode = 1;
	if (mode == 1)
		return (1);
	return (0);
}

int		buff_output(char *str, char *act)
{
	static char *buf;

	if (ft_strcmp(act, "new") == 0)
		buf = ft_strnew(1);
	if (ft_strcmp(act, "add") == 0)
	{
		buf = ft_strfreejoin(buf, str, 1);
		buf = ft_strfreejoin(buf, "\n", 1);
	}
	if (ft_strcmp(act, "print") == 0)
	{
		ft_putendl(buf);
		free(buf);
	}
	return (1);
}

void	send_parsing(char *line, int *end, int *start, t_rooms **rooms)
{
	static int i = -1;

	buff_output(line, "add");
	if (line[0] != '#' && ft_strchr(line, ' ') != 0 &&
			tubemode(0) == 0 && ++i >= 0)
	{
		if (*end == 1 && (*end = 0) == 0)
			add_room(rooms, line, i, "end");
		else if (*start == 1 && (*start = 0) == 0)
			add_room(rooms, line, i, "start");
		else
			add_room(rooms, line, i, "");
	}
	if (line[0] != '#' && ft_strchr(line, ' ') != 0 && tubemode(0) == 1)
		stop_parse(1, 0);
	if (line[0] != '#' && ft_strchr(line, ' ') == 0)
		add_tube(rooms, line);
	if (line[0] == '#' && ft_strcmp(line, "##end") == 0)
		*end = 1;
	else if (line[0] == '#' && ft_strcmp(line, "##start") == 0)
		*start = 1;
	free(line);
}

int		parser(int ants)
{
	char	*line;
	t_rooms	*rooms;
	t_paths	*paths;
	int		end;
	int		start;

	rooms = NULL;
	start = 0;
	end = 0;
	while (stop_parse(0, -1) == 0 && get_next_line(0, &line) == 1)
		send_parsing(line, &end, &start, &rooms);
	while (get_next_line(0, &line) == 1 && buff_output(line, "add"))
		free(line);
	free(line);
	if (start_distance(&rooms) != 0 && buff_output(line, "print"))
	{
		paths = find_paths(rooms);
		resolve(paths, rooms, ants);
		ft_pathdel(&paths);
	}
	else
		ft_putendl_fd("Cannot resolve this map\nERROR", 2);
	ft_roomdel(&rooms);
	return (0);
}

int		main(void)
{
	char	*line;
	long	ants;
	char	*tmp;
	int		ret;

	buff_output(NULL, "new");
	while ((ret = get_next_line(0, &line)) == 1 && line[0] == '#')
	{
		buff_output(line, "add");
		if (line[0] == '#')
			free(line);
	}
	buff_output(line, "add");
	if (ret == 1 && ft_isstrdigit(line))
		ants = ft_atoll(line);
	else
		return (write(2, "No ants or non-digit ant count\nERROR\n", 37));
	tmp = ft_strtrim(line);
	free(line);
	line = tmp;
	if (!ft_isstrdigit(line) || ants == 9999999999 || ants < 0)
		return (write(2, "Overflow/Underflow ant number\nERROR\n", 36));
	parser((int)ants);
	free(tmp);
	return (0);
}
