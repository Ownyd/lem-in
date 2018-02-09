/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:30:27 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:15:38 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define MAXPATH 100
# define A_R 9999999999

typedef struct		s_paths
{
	char			*p;
	int				len;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_tubes
{
	int				n;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_rooms
{
	int				n;
	int				x;
	int				y;
	int				ds;
	int				de;
	int				start;
	int				end;
	int				ant;
	char			*name;
	struct s_tubes	*tubes;
	struct s_rooms	*next;
}					t_rooms;

#endif
