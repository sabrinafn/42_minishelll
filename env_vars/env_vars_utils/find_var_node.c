/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:20 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_envp_lst	*find_var_node(char *name)
{
	t_envp_lst	*ptr;

	if ((*env_vars_list(0)) == NULL)
		return (NULL);
	ptr = *env_vars_list(0);
	while (ptr != NULL)
	{
		if (ft_strncmp(name, ptr->var, ft_strlen(name) + 1) == 0)
		{
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}
