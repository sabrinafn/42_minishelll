/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:04 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(char *variable)
{
	t_envp_lst	**lst;
	t_envp_lst	*current;

	lst = env_vars_list(0);
	current = *lst;
	while (current)
	{
		if (ft_strcmp(variable, current->var) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
