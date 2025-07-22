/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2025/02/04 18:58:35 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_commands_list(t_args_lst **ptr, int run)
{
	if ((*ptr)->type == operators)
	{
		if (ft_strcmp((*ptr)->arg, "|") == 0)
		{
			push_command(*curr_cmd());
			run++;
			*curr_cmd() = new_command(run);
		}
		else
			parse_redirect(ptr);
	}
	else if ((*ptr)->type == string)
		add_word(&((*curr_cmd())->comm), ptr);
	if (*ptr)
		(*ptr) = (*ptr)->next;
}

void	run_commands(t_args_lst *ptr)
{
	int	run;

	run = 0;
	*curr_cmd() = new_command(run);
	while (ptr)
	{
		update_commands_list(&ptr, run);
	}
	if ((*curr_cmd()) == NULL)
		return ;
	(*curr_cmd())->not_last = 0;
	push_command(*curr_cmd());
	call_list_commands();
}

int	count_blocks(t_args_lst *ptr)
{
	int	ret;

	ret = 1;
	while (ptr)
	{
		if (ptr->type == operators)
			if (ft_strcmp(ptr->arg, "|") == 0)
				ret++;
		ptr = ptr->next;
	}
	return (ret);
}

void	make_pipes(t_pipe **pipeline)
{
	int	total_blocks;
	int	i;

	if (*pipeline != NULL)
		free(*pipeline);
	total_blocks = count_blocks(*args_list());
	if (total_blocks == 1)
	{
		*pipeline = NULL;
		return ;
	}
	*pipeline = malloc(sizeof(t_pipe) * (total_blocks));
	i = 0;
	while (i < (total_blocks - 1))
	{
		pipe((*pipeline)[i]);
		i++;
	}
}

void	call_list_commands(void)
{
	static t_pipe	*pipeline;
	int				total_blocks;
	int				i;

	make_pipes(&pipeline);
	total_blocks = count_blocks(*args_list());
	while (*command_lst() != NULL)
	{
		pop_command();
		run_curr_command(&pipeline, total_blocks);
	}
	i = 0;
	while ((i < (total_blocks - 1)))
	{
		close_t_pipe(pipeline[i]);
		i++;
	}
	*child_process() = 1;
	waitpid(*last_pid(), &i, 0);
	*child_process() = 0;
	if (WIFEXITED(i))
		*current_exit_code() = WEXITSTATUS(i);
	while (wait(&i) > 0)
		;
}
