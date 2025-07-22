/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:11 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 19:01:08 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	push_command(t_command *new_command)
{
	t_command	**head;

	head = command_lst();
	if (!new_command)
		return ;
	new_command->next = *head;
	*head = new_command;
}

t_command	*pop_command(void)
{
	t_command	**head;
	t_command	*removed_command;

	head = command_lst();
	if (!*head)
		return (NULL);
	removed_command = *head;
	*head = (*head)->next;
	removed_command->next = NULL;
	*curr_cmd() = removed_command;
	return (removed_command);
}

t_command	*new_command(int run)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->run = run;
	cmd->next = NULL;
	cmd->comm = NULL;
	cmd->input = STDIN_FILENO;
	cmd->output = STDOUT_FILENO;
	cmd->not_last = 1;
	cmd->here[0] = -1;
	cmd->here[1] = -1;
	return (cmd);
}

void	free_t_command(t_command **cmd)
{
	if (!cmd || !(*cmd))
		return ;
	free_args_list(&((*cmd)->comm));
	if ((*cmd)->here[0] != -1)
		close((*cmd)->here[0]);
	if ((*cmd)->here[1] != -1)
		close((*cmd)->here[1]);
	free((*cmd));
	cmd = NULL;
}

void	free_cmd_lst(t_command	**head)
{
	if ((head == NULL) || (*head == NULL))
		return ;
	free_cmd_lst(&(*head)->next);
	free_t_command(head);
}
