/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:27:20 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:20:24 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_output_to_file(char *s)
{
	if (ft_strcmp(s, ">") == 0)
		return (1);
	if (ft_strcmp(s, ">>") == 0)
		return (1);
	return (0);
}

int	is_input_from_file(char *s)
{
	if (ft_strcmp(s, "<") == 0)
		return (1);
	return (0);
}

int	is_input_from_heredoc(char *s)
{
	if (ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}
