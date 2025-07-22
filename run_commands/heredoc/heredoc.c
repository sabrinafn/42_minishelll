/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/03 15:03:39 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc(t_args_lst **ptr, char *line)
{
	(*ptr) = (*ptr)->next;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			write_stderr("Warning: here-document ended by EOF", 1);
			break ;
		}
		if ((line != NULL) && ((ft_strcmp((*ptr)->arg, line) != 0)))
		{
			write((*curr_cmd())->here[1], line, ft_strlen(line));
			write((*curr_cmd())->here[1], "\n", 1);
		}
		else
			break ;
		free(line);
	}
	free(line);
}
