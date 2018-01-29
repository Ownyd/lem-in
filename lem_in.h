/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:30:27 by tlux              #+#    #+#             */
/*   Updated: 2018/01/29 10:21:14 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

typedef struct 		s_tubes
{
	int				n;
	struct s_tubes	*next;
}					t_tubes;

typedef struct		s_rooms
{
	int				n;
	int				x;
	int				y;
	char			*name;
	struct s_tubes	*tubes;
	struct s_rooms	*next;
}					t_rooms;

#endif
