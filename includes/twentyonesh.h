/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twentyonesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:54:48 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/30 16:05:02 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTYONESH_H
# define TWENTYONESH_H

# include "minishell.h"
# include <termios.h>
# include <termcap.h>

typedef struct	s_to
{
	struct termios	tattr;
	int				x;
	char			**history;
	int				y;
	int				max_x;
	int				old_x;
	struct termios	b_tattr; //Save a pointer to the old terminal to reset
}				t_to;

void			init_term(t_to *to);
int				ft_getline(char **line, t_to *to);
int				ft_ft_putchar(int c);
char			*ft_addchar(char *line, char c, int index);
void			ft_print(char c, char **line, t_to *to);
void			reset_term(t_to *term);
int				ft_move_cursor(char c, t_to *to, char **line);
char			*ft_removechar(t_to *to, char *line, int index);
int				ft_replace_cursor(t_to *to);
int				ft_cursorend(t_to *to);
char			**ft_addhistory(char **tab, char *str);
char			*ft_histup(t_to *to, char *line);
void			ft_clear(t_to *to);
char			*ft_histdown(t_to *to, char *line);

#endif
