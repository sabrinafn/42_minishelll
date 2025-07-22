/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_environment_vars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:16:40 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/31 14:27:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_pos_strchr(char *str, char c)
{
	char	*strchr_return;

	strchr_return = ft_strchr(str, c);
	if (strchr_return != NULL)
		return (strchr_return - str);
	return (-1);
}

void	add_to_lst(t_envp_lst **env_var, char *env)
{
	t_envp_lst	*temp;
	t_envp_lst	*new_node;

	temp = *env_var;
	new_node = (t_envp_lst *)malloc(sizeof(t_envp_lst));
	if (new_node == NULL)
	{
		return ;
	}
	new_node->var = ft_substr(env, 0, find_pos_strchr(env, '='));
	new_node->value = ft_substr(env, find_pos_strchr(env, '=') + 1,
			ft_strlen(env));
	new_node->next = NULL;
	if (temp == NULL)
	{
		*env_var = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

t_envp_lst	*store_envp(char **envp)
{
	int			i;
	t_envp_lst	*env_var;

	i = 0;
	env_var = NULL;
	while (envp[i])
	{
		add_to_lst(&env_var, envp[i]);
		i++;
	}
	return (env_var);
}
