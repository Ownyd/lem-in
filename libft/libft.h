/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:12:12 by tlux              #+#    #+#             */
/*   Updated: 2018/02/09 19:19:32 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../lem_in.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <locale.h>
# include <limits.h>
# define BUFF_SIZE 10

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_tubedel(t_tubes **alst);
int					tubemode(int n);
void				add_room(t_rooms **rooms, char *line,
		int number, char *act);
void				add_tube(t_rooms **rooms, char *line);
int					stop_parse(int c, int err);
int					duplicate_name(char *str, t_rooms *rooms);
int					non_tube(char *str);
void				ft_tabfree(char **tab);
void				ft_roomdel(t_rooms **alst);
void				ft_pathdel(t_paths **alst);
void				resolve(t_paths *paths, t_rooms *rooms, int ants);
t_rooms				*find_room_extrems(char *search, t_rooms *lst);
int					start_distance(t_rooms **rooms);
void				ft_pathadd(t_paths **alst, t_paths *new);
t_paths				*ft_pathnew(char *p);
t_paths				*find_paths(t_rooms *rooms);
t_rooms				*find_room_by_name(char *name, t_rooms *lst);
t_rooms				*find_room(int number, t_rooms *lst);
t_tubes				*ft_tubenew(int number);
void				ft_tubeadd(t_tubes **alst, t_tubes *new);
t_rooms				*ft_roomnew(char *name, int coord_x,
		int coord_y, int number);
void				ft_roomadd(t_rooms **alst, t_rooms *new);
long long			ft_atoll(const char *str);
int					ft_isstrdigit(char *str);
long long			ft_atoll(const char *str);
char				*ft_strfreesub(char *s, unsigned int start, size_t len);
char				*ft_strfreejoin(char *s1, char *s2, int choice);
int					get_next_line(const int fd, char **line);
int					ft_count_if(char **tab, int (*f)(char*));
void				ft_foreach(int *tab, int length, void (*f)(int));
void				ft_print_params(char *name);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_contdel(void *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char *str);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
