/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_to_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:48:28 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/29 02:20:19 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output_to_file(int *file)
{
	if (*file == -1)
		return ;
	dup2(*file, STDOUT_FILENO);
	close(*file);
}
