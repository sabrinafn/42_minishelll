/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:00:27 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 16:00:29 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_by_redirects(t_args_lst **split, char *str, int *i)
{
	char	redirect;
	int		len;
	int		start;

	len = 0;
	start = *i;
	redirect = str[start];
	start++;
	len++;
	while (str[start] == redirect)
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
}
