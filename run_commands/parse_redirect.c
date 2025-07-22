/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:14:22 by fernando          #+#    #+#             */
/*   Updated: 2025/02/04 18:44:46 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirect(t_args_lst **ptr)
{
	if (((*curr_cmd())->input == -1) || ((*curr_cmd())->output == -1))
		return ;
	if (is_output_to_file((*ptr)->arg))
		redirect_output((*curr_cmd()), ptr);
	if (is_input_from_file((*ptr)->arg))
		redirect_input((*curr_cmd()), ptr);
	if (is_input_from_heredoc((*ptr)->arg))
		call_heredoc(ptr, 0);
}

void	call_heredoc_continue(int *status, t_args_lst **ptr)
{
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	if (*running_loop() == 1)
		return ;
	(*ptr) = (*ptr)->next;
	if (*status == 130)
	{
		(*ptr) = NULL;
		free_args_list(args_list());
		free_t_command(curr_cmd());
		*curr_cmd() = NULL;
		free_cmd_lst(command_lst());
		write_human_stdout("", 1);
	}
	handle_signals();
}

void	call_heredoc(t_args_lst **ptr, pid_t pid)
{
	int	status;

	close_t_pipe((*curr_cmd())->here);
	pipe((*curr_cmd())->here);
	(*curr_cmd())->input = (*curr_cmd())->here[0];
	handle_signals_heredoc();
	pid = fork();
	if (pid == 0)
	{
		*child_process() = 1;
		rl_clear_history();
		if (((*ptr)->next->is_quoted) == false)
			heredoc(ptr, NULL);
		else
			heredoc_expand(ptr, NULL, NULL);
		close((*curr_cmd())->here[0]);
		close((*curr_cmd())->here[1]);
		free_all();
		exit(0);
	}
	while (waitpid(pid, &status, 0) == -1 && errno == EINTR)
		;
	close((*curr_cmd())->here[1]);
	call_heredoc_continue(&status, ptr);
}

void	free_all(void)
{
	close_all();
	free_t_command((curr_cmd()));
	free_cmd_lst(command_lst());
	free_args_list(args_list());
	free_env_lst(env_vars_list(0));
}
