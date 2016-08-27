/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twentyonesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:54:48 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/27 14:40:11 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTYONESH_H
# define TWENTYONESH_H

# include "minishell.h"
# include <termios.h>
# include <term.h>
# include <termcap.h>

typedef struct	s_to
{
	struct termios	tattr;
	int				x;
	int				max_x;
	int				old_x;
	struct termios	b_tattr; //Save a pointer to the old terminal to reset
}				t_to;

void			init_term(t_to *to);
int				ft_getline(char **line, t_to *to);
int				ft_ft_putchar(int c);
char			*ft_addchar(char *line, char c);
void			ft_print(char c, char **line, t_to *to);
void			reset_term(t_to *term);
void			ft_move_cursor(char c, t_to *to);
char			*ft_removechar(t_to *to, char *line, int index);
void			ft_replace_cursor(t_to *to);
void			ft_cursorend(t_to *to);

#endif
