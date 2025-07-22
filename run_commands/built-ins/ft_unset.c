/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:27 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:20:18 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_unset_run(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		remove_env_var(argv[i++]);
	*current_exit_code() = 0;
}

void	ft_unset(char **argv)
{
	(void)argv;
}
