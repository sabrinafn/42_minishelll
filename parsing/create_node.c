/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:03:21 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 18:02:57 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
{
	t_args_lst	*new_lst;
	t_args_lst	*temp;

	new_lst = (t_args_lst *)malloc(sizeof(t_args_lst));
	temp = *args_lst;
	new_lst->arg = ft_substr(str, start, len);
	new_lst->type = string;
	new_lst->next = NULL;
	if (temp == NULL)
		*args_lst = new_lst;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_lst;
		new_lst->next = NULL;
	}
}
