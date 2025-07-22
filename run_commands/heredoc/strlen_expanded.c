/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_expanded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:01:31 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:19:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	strlen_expanded(char *line)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$')
		{
			total = total + ft_envlen(line, i);
			i++;
			while (not_end_env_var(line[i]))
				i++;
		}
		else
		{
			total++;
			i++;
		}
	}
	return (total);
}
