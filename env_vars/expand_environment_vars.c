/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environment_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 17:39:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_expand(char **str, int *i)
{
	char	*value;
	char	*var;
	char	*expanded;
	int		new_len;
	int		pos;

	var = parse_var_found((*str) + *i);
	value = get_var_value(var);
	new_len = ft_strlen(*str) - ft_strlen(var) + ft_strlen(value);
	expanded = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!expanded)
		return (NULL);
	ft_memcpy(expanded, *str, *i);
	ft_memcpy(expanded + *i, value, ft_strlen(value));
	pos = *i + ft_strlen(var) + 1;
	ft_strcpy(expanded + *i + ft_strlen(value), *str + pos);
	free(var);
	free(value);
	return (expanded);
}

void	update_quotes(char c, bool *single_quotes, bool *double_quotes)
{
	if (c == '\"' && *single_quotes == false)
		*double_quotes = !*double_quotes;
	if (c == '\'' && *double_quotes == false)
		*single_quotes = !*single_quotes;
}

int	handle_dollar_expansion(char **str, int index, bool *single_quotes)
{
	char	*temp;
	char	*original;

	temp = NULL;
	original = *str;
	if ((*str)[index] == '$' && !*single_quotes)
	{
		if (is_single_quote(*str, index))
			return (1);
		if ((*str)[index + 1] == '$')
			index++;
		else if ((*str)[index + 1] == '\"')
			remove_dollar_sign(str, index);
		else if ((*str)[index + 1] != ' ' && (*str)[index + 1] != '\"')
		{
			temp = ft_expand(str, &index);
			free(*str);
			(*str) = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
	}
	if (original != *str)
		return (0);
	return (1);
}

void	handle_environment_vars_expansion(char **str)
{
	bool	single_quotes;
	bool	double_quotes;
	int		i;

	single_quotes = false;
	double_quotes = false;
	i = 0;
	while ((*str)[i] && (*str)[i + 1])
	{
		update_quotes((*str)[i], &single_quotes, &double_quotes);
		if (handle_dollar_expansion(str, i, &single_quotes))
			i++;
	}
}
