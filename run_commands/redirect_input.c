/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 15:07:52 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input(t_command *command, t_args_lst **ptr)
{
	int	fd;

	if (command->input == -1)
		return ;
	(*ptr) = (*ptr)->next;
	fd = open((*ptr)->arg, O_RDONLY);
	if (fd == -1)
		write_stderr(" No such file or directory", 1);
	command->input = fd;
}
