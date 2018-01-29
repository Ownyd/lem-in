/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:21:25 by tlux              #+#    #+#             */
/*   Updated: 2018/01/27 02:25:46 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbrword(char const *s, char c)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] != c && s[i] != 0)
				i++;
			if (s[i] == 0)
				break ;
		}
		i++;
	}
	return (ret);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	*ft_copyword(char const *s, char c)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wordlen(s, c))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if ((i = 0) == 0 && s == NULL)
	{
		ret = NULL;
		return (ret);
	}
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_nbrword(s, c) + 1))))
		return (NULL);
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			ret[j] = ft_copyword(&s[i], c);
			i += ft_wordlen(&s[i], c);
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
