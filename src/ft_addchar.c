/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 17:37:14 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/25 18:43:46 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	*ft_addchar(char *line, char c)
{
	char	*str;

	str = ft_strnew(ft_strlen(line) + 2);
	*str = '\0';
	ft_strcpy(str, line);
	str[ft_strlen(str)] = c;
	free (line);
	line = NULL;
	return (str);
}
