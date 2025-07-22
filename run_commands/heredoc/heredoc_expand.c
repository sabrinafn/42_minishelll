/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:30:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:01 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_expand(t_args_lst **ptr, char *line, char *e_l)
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
		if ((line != NULL) && (ft_strcmp((*ptr)->arg, line) != 0))
		{
			e_l = expand_env_vars_heredoc(line);
			free(line);
			write((*curr_cmd())->here[1], e_l, ft_strlen(e_l));
			free(e_l);
		}
		else
			break ;
	}
	free(line);
}
