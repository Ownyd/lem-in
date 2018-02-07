/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 02:26:14 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 03:27:34 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ncurses.h>
#include <string.h> 
#include "../libft/libft.h"
#include "visu.h"

static t_struct ft_init(void)
{
	t_struct infos;
	infos.row = 0;
	infos.col = 0;
	infos.sn = NULL;
	infos.en = NULL;
	infos.nbpath = 0;
	infos.lengthpath = 0;
	infos.start = 0;
	infos.end = 0;
	infos.split = NULL;
	return (infos);
}
int main(void)
{
	t_struct infos;
	char *line;

	infos = ft_init();
	while(get_next_line(0, &line) == 1 && line[0] != '\0')
	{
		if (infos.start == 1 && (infos.start = 0) == 0 && line[0] != '#' &&
				ft_strchr(line, ' ') != 0)
			{
				infos.split = ft_strsplit(line, "\t ");
				infos.sn = infos.split[0];
			}
		if (ft_strcmp("##start", line) == 0)
			infos.start = 1;
	}
	printf(KRED"%s\n"KNRM,infos.sn);
	return(0);
}
