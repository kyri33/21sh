#include "21sh.h"

int	ft_ft_putchar(int c)
{
	return (write(2, &c, 1));
}

void	init_term(t_term *term)
{
	tcgetattr(0, &term->tattr);
	//tputs(tgetstr("ti", NULL), 1, ft_ft_putchar);
	//tputs(tgetstr("ho", NULL), 1, ft_ft_putchar);
	term->tattr.c_lflag &= ~(ECHO | ICANON);
	//term->tattr.c_cc[VMIN] = 1;
	//term->tattr.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term->tattr);
	//tputs(tgetstr("vi", NULL), 1, ft_ft_putchar);
}
