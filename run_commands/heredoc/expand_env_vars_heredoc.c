/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_vars_heredoc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:21:14 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:20:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_env_vars_heredoc(char *line)
{
	int		total_chars;
	char	*return_string;

	total_chars = strlen_expanded(line);
	return_string = malloc(total_chars + 2);
	expand_vars_to_string(return_string, line);
	return (return_string);
}
