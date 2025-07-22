/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_value_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:58:07 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:25:16 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var_value_heredoc(char *line, int i)
{
	char	*env_var;
	int		var_name_size;
	char	*var_name;
	int		j;

	var_name_size = 1;
	while (not_end_env_var(line[i + var_name_size]))
		var_name_size++;
	var_name = malloc(sizeof(char) * (var_name_size));
	i++;
	j = 0;
	while (not_end_env_var(line[i]))
		var_name[j++] = line[i++];
	var_name[j] = '\0';
	env_var = ft_getenv(var_name);
	free(var_name);
	if (env_var == NULL)
		return ("\0");
	return (env_var);
}
