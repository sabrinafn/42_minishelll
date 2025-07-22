/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:12:46 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 20:12:48 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_lst(t_args_lst *node)
{
	if (!node)
		return ;
	free_lst(node->next);
	free(node->arg);
	free(node);
	node = NULL;
}

void	free_args_list(t_args_lst **args_lst)
{
	if (!args_lst || !*args_lst)
		return ;
	if (!*args_lst)
	{
		free(args_lst);
		return ;
	}
	free_lst(*args_lst);
	*args_lst = NULL;
}
