/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env_vars_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:09:11 by fernando          #+#    #+#             */
/*   Updated: 2024/12/04 16:16:06 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	clear_env_vars_lst(t_envp_lst **lst)
{
	t_envp_lst	*ptr;
	t_envp_lst	*prev;

	if (*lst == NULL)
		return ;
	ptr = (*lst);
	while (ptr != NULL)
	{
		prev = ptr;
		ptr = ptr->next;
		free(prev->value);
		free(prev->var);
		free(prev);
	}
}
