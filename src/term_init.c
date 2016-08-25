/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:52:44 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/25 18:33:59 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int		ft_ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_term(t_to *term)
{
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &term->tattr);
	tcgetattr(0, &term->b_tattr);
	tputs(tgetstr("ti", NULL), 1, ft_ft_putchar); //Clears the screen
	tputs(tgetstr("ho", NULL), 1, ft_ft_putchar); //Places cursor at top left of screen
	term->tattr.c_lflag &= ~(ECHO | ICANON);
	term->tattr.c_cc[VMIN] = 1;
	term->tattr.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term->tattr);
	//tputs(tgetstr("vi", NULL), 1, ft_ft_putchar); make the cursor invisible.
	term->x = -1;
}

void	reset_term(t_to *term)
{
	tcsetattr(0, 0, &term->b_tattr);
}
