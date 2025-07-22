/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:07:06 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/30 15:11:03 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_free_lst(t_envp_lst **node)
{
	if (!*node)
		return ;
	env_free_lst(&(*node)->next);
	free((*node)->var);
	free((*node)->value);
	free(*node);
	*node = NULL;
}

void	free_env_lst(t_envp_lst **env_lst)
{
	if (!env_lst || !*env_lst)
		return ;
	env_free_lst(env_lst);
	*env_lst = NULL;
}
