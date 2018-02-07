/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 02:51:11 by tlux              #+#    #+#             */
/*   Updated: 2018/02/07 03:25:04 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

typedef struct	s_struct
{
	int row;
	int col;
	char *sn;
	char *en;
	int nbpath;
	int lengthpath;
	int start;
	int end;
	char **split;
}				t_struct;
