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
