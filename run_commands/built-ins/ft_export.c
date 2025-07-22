/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:14 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 19:06:28 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export_run(char **argv)
{
	int	i;

	i = 0;
	if (!valid_export_call())
		return ;
	while (argv[i] != NULL)
		i++;
	if (i == 1)
		return ;
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "=") == 0)
		{
			*current_exit_code() = 1;
			write_stderr(" not a valid identifier", 1);
			return ;
		}
		add_env_var(argv[i++]);
	}
	if ((*current_exit_code()) != 1)
		*current_exit_code() = 0;
}

int	valid_export_call(void)
{
	t_args_lst	*ptr;

	ptr = *args_list();
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->arg, "|") == 0)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	ft_export(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	if (i == 1)
	{
		list_env_vars_ordered();
		return ;
	}
	(void)argv;
}
