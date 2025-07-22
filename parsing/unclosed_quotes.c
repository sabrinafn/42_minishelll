/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:21 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/03 19:26:47 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	quotes_are_balanced(char *str)
{
	int		i;
	bool	s_quotes;
	bool	d_quotes;

	if (str == NULL)
		return (true);
	i = 0;
	s_quotes = false;
	d_quotes = false;
	while (str[i])
	{
		if (str[i] == '\'' && d_quotes == false)
			s_quotes = !s_quotes;
		if (str[i] == '\"' && s_quotes == false)
			d_quotes = !d_quotes;
		i++;
	}
	if (s_quotes || d_quotes)
		return (false);
	return (true);
}
