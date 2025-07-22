/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:21:32 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:19:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_envlen(char *line, int i)
{
	char	*env_var;
	int		var_size;
	char	*var_name;
	int		j;

	var_size = 1;
	while (not_end_env_var(line[i + var_size]))
		var_size++;
	var_name = malloc(sizeof(char) * (var_size));
	i++;
	j = 0;
	while (not_end_env_var(line[i]))
		var_name[j++] = line[i++];
	var_name[j] = '\0';
	env_var = ft_getenv(var_name);
	if (env_var != NULL)
		j = ft_strlen(env_var);
	else
		j = 0;
	free(var_name);
	return (j);
}
