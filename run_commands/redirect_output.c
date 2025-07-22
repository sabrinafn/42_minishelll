/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:33:46 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 15:07:42 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_output(t_command *command, t_args_lst **ptr)
{
	int	fd;

	fd = open_file(ptr);
	if (fd == -1)
		write_stderr(" Permission denied or no such file", 1);
	command->output = fd;
}
