/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:54 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 01:59:03 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	print_env_vars_list(t_envp_lst *lst, char *line, char *c)
{
	while (lst != NULL)
	{
		if (line != NULL)
			printf("%s ", line);
		if (lst->value != NULL)
			printf("%s=%s%s%s\n", lst->var, c, lst->value, c);
		else
			printf("%s\n", lst->var);
		lst = lst->next;
	}
}
