/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:56:36 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 18:04:49 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_pipes(t_command *command, t_pipe **pipeline, int t)
{
	int	i;

	i = 0;
	if (command->here[1] != -1)
		close(command->here[1]);
	while ((i < (t - 1)))
	{
		close_t_pipe((*pipeline)[i]);
		i++;
	}
}

void	set_process_io(t_pipe **pipeline, int t)
{
	if (((*curr_cmd())->input == -1) || ((*curr_cmd())->output == -1))
		exit(1);
	if ((*curr_cmd())->output != STDOUT_FILENO)
	{
		dup2((*curr_cmd())->output, STDOUT_FILENO);
		close((*curr_cmd())->output);
	}
	else if ((*curr_cmd())->not_last == 1)
		dup2((*pipeline)[(*curr_cmd())->run][1], STDOUT_FILENO);
	if ((*curr_cmd())->input != STDIN_FILENO)
	{
		dup2((*curr_cmd())->input, STDIN_FILENO);
		close((*curr_cmd())->input);
	}
	else if ((*curr_cmd())->run != 0)
		dup2((*pipeline)[(*curr_cmd())->run - 1][0], STDIN_FILENO);
	close_pipes((*curr_cmd()), pipeline, t);
	free(*pipeline);
}

void	close_t_pipe(t_pipe pipe)
{
	if (pipe[1] != -1)
		close(pipe[1]);
	if (pipe[0] != -1)
		close(pipe[0]);
}
