/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_to_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:48:41 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/29 02:22:37 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output_to_pipe(t_pipe *pipe)
{
	if ((*pipe)[0] != -1)
		close((*pipe)[0]);
	dup2((*pipe)[1], STDOUT_FILENO);
	if ((*pipe)[1] != -1)
		close((*pipe)[1]);
}
