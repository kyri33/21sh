/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 16:53:16 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/27 17:22:59 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char   	**ft_addhistory(char **tab, char *str)
{
	char   	**temp;
	int    		i;
	int    		x;

	i = 0;
	x = 0;
	temp = (char **)malloc(sizeof(char*) * 11);
	temp[i] = ft_strdup(str);
	i++;
	while (i < 10)
	{
		if (tab[x])
			temp[i] = ft_strdup(tab[x]);
		else
			temp[i] = 0;
		i++;
		x++;
	}
	free_tab(tab);
	return (temp);
}

char	*ft_histup(t_to *to, char *line)
{
	if (to->y < 10)
	{
		if (to->history[to->y])
		{
			free(line);
			to->y++;
			return (to->history[y]);
		}
	}
	return (line);
}
