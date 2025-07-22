/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:13:01 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 20:13:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_split(char ***spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while ((*spl)[i] != NULL)
	{
		free((*spl)[i]);
		i++;
	}
	free(*spl);
}
