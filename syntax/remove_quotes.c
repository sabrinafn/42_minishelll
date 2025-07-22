/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_outer_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:45:22 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/29 04:02:59 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

void	remove_one_quote(char **str, int i)
{
	char	*temp;
	int		new_len;
	int		old_len;

	old_len = ft_strlen((*str));
	new_len = old_len - 1;
	temp = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!temp)
		return ;
	ft_memcpy(temp, (*str), i);
	ft_strcpy(temp + i, (*str) + i + 1);
	free(*str);
	(*str) = ft_strdup(temp);
	free(temp);
	temp = NULL;
}

void	check_quotes_and_remove(char **str)
{
	bool	single_quotes;
	bool	double_quotes;
	int		i;

	single_quotes = false;
	double_quotes = false;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' && !double_quotes)
		{
			single_quotes = !single_quotes;
			remove_one_quote(str, i);
		}
		else if ((*str)[i] == '\"' && !single_quotes)
		{
			double_quotes = !double_quotes;
			remove_one_quote(str, i);
		}
		else
			i++;
	}
}
