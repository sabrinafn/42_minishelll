/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 15:45:45 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_envinroment_vars(char **envp)
{
	t_envp_lst	*env_vars;

	env_vars = store_envp(envp);
	*env_vars_list(0) = env_vars;
}

static char	*init_program(void)
{
	char	*line;
	char	*prompt;

	handle_signals();
	if (isatty(STDIN_FILENO))
		reset_terminal_settings();
	*running_loop() = 0;
	*child_process() = 0;
	prompt = get_prompt();
	line = readline(prompt);
	free(prompt);
	return (line);
}

static int	validate_args_list(void)
{
	t_args_lst	*temp;

	while ((*args_list()) && (ft_strcmp((*args_list())->arg, "") == 0))
	{
		temp = (*args_list());
		*args_list() = (*args_list())->next;
		free(temp);
	}
	if (*args_list() == NULL)
		return (0);
	if ((*args_list())->arg[0] == '#')
		return (0);
	if (!handle_syntax(args_list()))
	{
		write_stderr("syntax error", 1);
		return (0);
	}
	return (1);
}

static int	parse_line_and_create_struct(char *line)
{
	t_args_lst	*temp;

	handle_environment_vars_expansion(&line);
	free_args_list(args_list());
	*args_list() = ft_lst_split(line);
	free(line);
	if (*args_list() == NULL)
		return (0);
	ft_lexer(args_list());
	if (!validate_args_list())
	{
		temp = *args_list();
		while (temp)
		{
			*args_list() = temp->next;
			free(temp->arg);
			free(temp);
			temp = *args_list();
		}
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;

	(void)ac;
	(void)av;
	line = NULL;
	init_envinroment_vars(envp);
	while (1)
	{
		line = init_program();
		if (!line)
			break ;
		if (line[0] != '\0')
			add_history(line);
		if (!parse_line_and_create_struct(line))
			continue ;
		run_commands(*args_list());
		free_args_list(args_list());
	}
	close_all();
	free_env_lst(env_vars_list(0));
	rl_clear_history();
}
