/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:11 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 17:50:13 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	**command_lst(void)
{
	static t_command	*a;

	return (&a);
}

pid_t	*last_pid(void)
{
	static pid_t	a;

	return (&a);
}

t_command	**curr_cmd(void)
{
	static t_command	*a;

	return (&a);
}
