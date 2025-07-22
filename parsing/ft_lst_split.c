/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:06:18 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/03 20:02:33 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char *str, int *i)
{
	while (!ends_space_block(str[*i]))
		(*i)++;
	while (!quotes_are_balanced(str + *i))
	{
		(*i)++;
		while (!ends_space_block(str[*i]))
			(*i)++;
		if ((*i) >= ft_strlen(str))
			break ;
	}
}

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	if (!quotes_are_balanced(str))
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			split_by_redirects(&split, str, &i);
		else
		{
			split_by_spaces(&split, str, i);
			skip_spaces(str, &i);
		}
	}
	return (split);
}
