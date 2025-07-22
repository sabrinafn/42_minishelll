/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_from_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:47:57 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/29 02:21:31 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	input_from_pipe(t_pipe *pipe)
{
	if ((*pipe)[1] != -1)
		close((*pipe)[1]);
	dup2((*pipe)[0], STDIN_FILENO);
	if ((*pipe)[0] != -1)
		close((*pipe)[0]);
}
