/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 09:31:43 by kioulian          #+#    #+#             */
/*   Updated: 2016/09/06 12:05:12 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_exit(t_env *e, t_to *to)
{
	free(e->line);
	e->line = NULL;
	free_tab(e->environ);
	free_tab(to->history);
	reset_term(to);
}
