/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:24:02 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 16:49:43 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_commands(t_built_in *cmds)
{
	free(cmds[0].name);
	free(cmds[1].name);
	free(cmds[2].name);
	free(cmds[3].name);
	free(cmds[4].name);
	free(cmds[5].name);
	free(cmds[6].name);
	free(cmds);
}
