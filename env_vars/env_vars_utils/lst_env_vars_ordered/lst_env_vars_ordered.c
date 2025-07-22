/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_vars_ordered.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:42:03 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:39 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	list_env_vars_ordered(void)
{
	t_envp_lst	*src;
	t_envp_lst	*ordered;
	t_envp_lst	*new;

	src = *env_vars_list(0);
	ordered = NULL;
	while (src != NULL)
	{
		new = var_dup(src);
		add_in_place(new, &ordered);
		src = src->next;
	}
	print_env_vars_list(ordered, "declare -x", "\"");
	clear_env_vars_lst(&ordered);
}
