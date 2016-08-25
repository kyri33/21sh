/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:19:05 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/25 17:46:24 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_print(char c, char **line, t_to *to)
{
	if (!(*line))
		*line = ft_strnew(1);
	*line = ft_addchar(*line, c);
	//tputs(&c, 1, ft_ft_putchar);
	ft_putchar(c);
	to->x++;
}

int	ft_getline(char **line, t_to *to)
{
	char	b[6];

	ft_strclr(b);
	read(0, b, 6);
	(void) **line;
	(void) *to;
	if (ft_isprint(b[0]))
		ft_print(b[0], line, to);
	else if (b[0] == 10)
	{
		ft_putstr("\n");
		return (0);
	}
	else
	{
		int	i = 0;
		while (b[i])
		{
			ft_putnbr(b[i]);
			ft_putchar(' ');
			i++;
		}
	}
	return (1);
}
