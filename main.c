/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:21:38 by tlux              #+#    #+#             */
/*   Updated: 2018/01/29 12:05:06 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(void)
{
	t_rooms *rooms;
	t_rooms *tmp;	
	ft_roomadd(&rooms, ft_roomnew("Metropolis", 1, 2, 0));
	ft_tubeadd(&(rooms->tubes), ft_tubenew(1));
	ft_tubeadd(&(rooms->tubes), ft_tubenew(2));
	ft_roomadd(&rooms, ft_roomnew("Westeros", 3, 4, 1));
	ft_roomadd(&rooms, ft_roomnew("Tatooine", 3, 4, 2));
	tmp = find_room(2, rooms);
	ft_tubeadd(&(rooms->tubes), ft_tubenew(3));
	ft_tubeadd(&(rooms->tubes), ft_tubenew(4));
	printf("Room name :%s\nRoom x :%d\nRoom y :%d\nRoom number :%d\nRoom tube :%d\nRoom 2nd tube :%d\n", tmp->name, tmp->x, tmp->y, tmp->n, tmp->tubes->n, tmp->tubes->next->n);
//	printf("Room name :%s\nRoom x :%d\nRoom y :%d\nRoom number :%d\n", rooms->name, rooms->x, rooms->y, rooms->n);
	return(0);
}
