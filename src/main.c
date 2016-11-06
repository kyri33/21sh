/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:37:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/06 11:58:08 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

pid_t	g_pid = -1;

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
	int	i;

	i = 0;
	e->commands = ft_strsplit(e->line, ';');
	while (e->commands[i])
	{
		e->args = ft_strsplit(e->commands[i], ' ');
		if (search_commands(e) > 0)
			run_command(e);
		i++;
		if (e->args)
			free_tab(e->args);
	}
	if (e->commands)
		free_tab(e->commands);
}

void	begin_shell(t_env *e, t_to *to)
{
	ft_putstr("21$h > ");
	ft_getline(&e->line, to);
	if (e->line && e->line[0] != ' ')
	{
		if (ft_strcmp(e->line, "exit") != 0)
		{
			process_line(e);
			free(e->line);
			e->line = NULL;
			begin_shell(e, to);
		}
		else
			ft_exit(e, to);
	}
	else
		begin_shell(e, to);
}

int		main(void)
{
	t_env		e;
	t_to		to;

	signal(SIGINT, signal_c);
	e.line = NULL;
	get_environ(&e);
	init_term(&to);
	begin_shell(&e, &to);
	return (1);
}
