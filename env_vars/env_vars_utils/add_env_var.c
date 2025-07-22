/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:08 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	LEAK FOUND WITH FREE_SPLIT() IN THIS FILE
	leak found when commenting of the free_split() calls.

	to see leak: export HELLO=123


	DOUBLE FREE WITH FREE_SPLIT() IN THIS FILE
	to see double free: export HELLO=123
						export HELLO=456 (overwrite the 123)
*/

void	add_variable(char **elements, char *var)
{
	t_envp_lst	*ptr;

	ptr = find_var_node(elements[0]);
	if (var[ft_strlen(var) - 1] == '=')
		elements[1] = ft_strdup("");
	if (ptr != NULL)
	{
		free(ptr->value);
		ptr->value = ft_strdup(elements[1]);
		free(elements[1]);
		elements[1] = NULL;
		return ;
	}
	ptr = *env_vars_list(0);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = malloc(sizeof(t_envp_lst));
	ptr->next->var = ft_strdup(elements[0]);
	ptr->next->value = ft_strdup(elements[1]);
	ptr->next->next = NULL;
	free(elements[1]);
	elements[1] = NULL;
}

void	add_env_var(char *var)
{
	char	**elements;
	int		i;

	elements = ft_split(var, '=');
	i = 0;
	while (elements[i] != NULL)
		i++;
	if (is_valid_var(elements))
		add_variable(elements, var);
	else
	{
		*current_exit_code() = 1;
		write_stderr(" not a valid identifier", 1);
	}
	free_split(&elements);
}

int	is_valid_var(char **elements)
{
	int	i;

	if (elements == NULL)
		return (0);
	i = 0;
	while (elements[i] != NULL)
		i++;
	if (i > 2)
		return (0);
	if (!((elements[0][0] == '_') || ft_isalpha(elements[0][0])))
		return (0);
	i = 1;
	while (elements[0][i] != '\0')
	{
		if (!((elements[0][i] == '_') || ft_isalnum(elements[0][i])))
			return (0);
		i++;
	}
	return (1);
}
