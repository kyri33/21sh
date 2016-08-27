/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 17:37:14 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/27 14:40:17 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	*ft_removechar(t_to *to, char *line, int index)
{
	char	*str;
	int		i;
	int		x;

	str = ft_strnew(to->max_x);
	i = 0;
	x = 0;
	while (i < (to->max_x - 1))
	{
		if (i == index)
			x++;
		str[i] = line[x];
		x++;
		i++;
	}
	free(line);
	line = NULL;
	return (str);
}

char	*ft_addchar(char *line, char c)
{
	char	*str;

	str = ft_strnew(ft_strlen(line) + 2);
	*str = '\0';
	ft_strcpy(str, line);
	str[ft_strlen(str)] = c;
	free(line);
	line = NULL;
	return (str);
}
