/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:37:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/25 18:39:11 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int		search_commands(t_env *e)
{
	if (ft_strcmp(e->args[0], "cd") == 0)
	{
		if (!e->args[1] || chdir(e->args[1]) != 0)
			ft_putstr("cd: directory not found\n");
	}
	else if (ft_strcmp(e->args[0], "echo") == 0)
		ft_echo(e);
	else if (ft_strcmp(e->args[0], "setenv") == 0)
		ft_setenv(e);
	else if (ft_strcmp(e->args[0], "unsetenv") == 0)
	{
		if (!ft_unsetenv(e))
			ft_putstr("Variable not found\n");
	}
	else if (ft_strcmp(e->args[0], "env") == 0)
		ft_env(e);
	else
		return (search_paths(e));
	return (0);
}

void	process_line(t_env *e)
{
	e->args = ft_strsplit(e->line, ' ');
	if (search_commands(e) > 0)
		run_command(e);
}

void	begin_shell(t_env *e, t_to *to)
{
	ft_putstr("21$h > ");
	while (ft_getline(&e->line, to))
			;
	ft_putstr(e->line);
	if (ft_strcmp(e->line, "exit") != 0)
	{
		if (ft_strcmp(e->line, "") != 0)
		{
			process_line(e);
			free(e->line);
			e->line = NULL;
			if (e->args)
				free_tab(e->args);
		}
		begin_shell(e, to);
	}
	else
	{
		free(e->line);
		e->line = NULL;
		free_tab(e->environ);
	}
}

int		main(void)
{
	t_env		e;
	t_to		to;

	e.line = NULL;
	get_environ(&e);
	init_term(&to);
	begin_shell(&e, &to);
	return (1);
}
