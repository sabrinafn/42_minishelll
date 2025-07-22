/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_previous_var_in_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:12 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp_lst	*find_previous_var_in_list(char *name)
{
	t_envp_lst	*ptr;
	t_envp_lst	*prev;

	prev = *env_vars_list(0);
	ptr = prev->next;
	while (ptr != NULL)
	{
		if (ft_strncmp(name, ptr->var, ft_strlen(name) + 1) == 0)
			return (prev);
		prev = ptr;
		ptr = ptr->next;
	}
	return (NULL);
}
