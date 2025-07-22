/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:42:45 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 21:29:30 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_envp_lst	*var_dup(t_envp_lst *env_var)
{
	t_envp_lst	*new;

	new = malloc(sizeof(t_envp_lst));
	new->var = ft_strdup(env_var->var);
	if (env_var->value != NULL)
		new->value = ft_strdup(env_var->value);
	else
		new->value = NULL;
	new->next = NULL;
	return (new);
}
