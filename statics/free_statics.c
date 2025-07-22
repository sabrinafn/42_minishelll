/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:47:06 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 18:19:34 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_statics(void)
{
	int			i;
	t_built_in	*temp;

	free_args_list(args_list());
	free_t_command(command_lst());
	*command_lst() = NULL;
	free_env_lst(env_vars_list(0));
	i = 0;
	temp = *fill_commands();
	while (i < 7)
	{
		free(temp[i].name);
	}
	env_vars_list(1);
	free(*fill_commands());
}
