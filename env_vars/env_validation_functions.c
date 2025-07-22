/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_validation_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:52:28 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 15:52:35 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_single_quote(char *str, int i)
{
	if (str[i] == '$')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			return (1);
		if (str[i - 1] == '\'' && str[i + 1] == '\'')
			return (1);
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (1);
	}
	return (0);
}

int	is_inside_double_quotes(char *str, int pos)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			check = !check;
		if (i == pos && str[i] == '$' && check)
			return (1);
		i++;
	}
	return (0);
}

void	remove_dollar_sign(char **str, int i)
{
	char	*new_str;
	int		len;

	if (is_inside_double_quotes(*str, i))
		return ;
	len = ft_strlen(*str);
	new_str = (char *)malloc(len);
	if (!new_str)
		return ;
	memcpy(new_str, *str, i);
	memcpy(new_str + i, *str + i + 1, len - i);
	free(*str);
	*str = new_str;
}
