/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 11:11:10 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/26 11:41:24 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_move_left(t_to *to)
{
	if (to->x > 0)
	{
		to->x--;
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
	}
}

void	ft_move_right(t_to *to)
{
	if (to->x < to->max_x)
	{
		to->x++;
		tputs(tgetstr("nd", NULL), 1, ft_ft_putchar);
	}
}

void	ft_cursorend(t_to *to)
{
	while (to->x < to->max_x)
		ft_move_right(to);
}

void	ft_replace_cursor(t_to *to)
{
	int	i;

	i = to->x;
	while (i < to->max_x)
	{
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
		i++;
	}
}

void	ft_move_cursor(char c, t_to *to)
{
	if (c == 68)
		ft_move_left(to);
	else if (c == 67)
		ft_move_right(to);
	else if (c == 72) // home
		;
	else if (c == 65) // up
		;
	else if (c == 66) // down
		;
	else if (c == 70) // end
		;
}
