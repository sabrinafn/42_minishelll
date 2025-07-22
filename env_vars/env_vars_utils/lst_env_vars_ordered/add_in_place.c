/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:43:46 by fernando          #+#    #+#             */
/*   Updated: 2024/12/04 16:39:42 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	add_in_place(t_envp_lst *new, t_envp_lst **lst)
{
	t_envp_lst	*ptr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (compare_str(new->var, (*lst)->var) <= 0)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
	{
		if (compare_str(new->var, ptr->next->var) <= 0)
		{
			new->next = ptr->next;
			ptr->next = new;
			return ;
		}
		ptr = ptr->next;
	}
	ptr->next = new;
}
