/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_and_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:50:27 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 15:50:39 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parse_var_found(char *str)
{
	char	*var_found;
	int		i;
	int		start;
	int		len;

	var_found = NULL;
	i = 0;
	start = 0;
	len = 0;
	if (!ft_strchr(str, '$'))
		return (NULL);
	start = (int)(ft_strchr(str, '$') - str) + 1;
	i = start;
	len++;
	while ((ft_isalnum(str[i]) || str[i] == '_') && str[i] != '\0')
	{
		len++;
		i++;
	}
	if (str[i] != '?')
		len--;
	var_found = ft_substr(str, start, len);
	return (var_found);
}

char	*get_var_value(char *var)
{
	char	*value;

	value = NULL;
	if (ft_strcmp(var, "?") == 0)
	{
		value = ft_itoa(*current_exit_code());
		return (value);
	}
	if (ft_getenv(var))
		value = ft_strdup(ft_getenv(var));
	else
		value = ft_strdup("");
	return (value);
}
