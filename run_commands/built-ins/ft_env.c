/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:14 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/30 14:44:59 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "env") != 0)
		{
			*current_exit_code() = 127;
			return ;
		}
		i++;
	}
	print_env_vars_list(*env_vars_list(0), NULL, "");
	*current_exit_code() = 0;
}
