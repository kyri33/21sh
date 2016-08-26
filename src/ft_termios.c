/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:19:05 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/26 10:32:13 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_add(char c, char **line, t_to *to)
{
	if (!(*line))
		*line = ft_strnew(1);
	*line = ft_addchar(*line, c);
	ft_putchar(c);
	to->x++;
	to->max_x++;
}

int		ft_newline(t_to *to)
{
	ft_putstr("\n");
	to->x = 0;
	to->max_x = 0;
	return (0);
}

void	ft_backspace(t_to *to, char **line)
{
	if (to->x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
		tputs(" ", 1, ft_ft_putchar);
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
		to->x--;
	}
	(void) line;
}

int		ft_getline(char **line, t_to *to)
{
	while (1)
	{
		char	b[6];

		ft_strclr(b);
		read(0, b, 6);
		if (ft_isprint(b[0]))
			ft_add(b[0], line, to);
		else if (b[0] == 10)
			return (ft_newline(to));
		else if (b[0] == 27 && b[1] == 91 && b[2] != 51)
			ft_move_cursor(b[2], to);
		else if (b[0] == 127)
			ft_backspace(to, line);
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
	}
}
