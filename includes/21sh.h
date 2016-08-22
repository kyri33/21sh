#ifndef SH_H
# define SH_H

# include "minishell.h"
# include <termios.h>
# include <term.h>
# include <termcap.h>

typedef struct	s_term
{
	struct termios tattr;
}		t_term;

void	init_term(t_term *term);

#endif
