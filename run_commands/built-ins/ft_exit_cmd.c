/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:10 by fernando          #+#    #+#             */
/*   Updated: 2025/02/03 12:07:40 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	convert_exit_value(char *c_value)
{
	int	current_value;

	current_value = ft_atoi(c_value);
	if ((current_value == 0) && (ft_strcmp("0", c_value) != 0))
	{
		write_stderr(" numeric argument required", 1);
		return (2);
	}
	return ((short)current_value);
}

void	ft_exit_cmd(char **argv)
{
	write_human_stdout("exit", 1);
	free_env_lst(env_vars_list(0));
	free_args_list(args_list());
	free_t_command(command_lst());
	rl_clear_history();
	if ((argv == NULL) || (argv[1] == NULL))
		*current_exit_code() = 0;
	else if (argv[0] && argv[1] && argv[2] == NULL)
		*current_exit_code() = convert_exit_value(argv[1]);
	else
	{
		write_stderr(" too many arguments", 1);
		*current_exit_code() = 1;
	}
	free_split(&argv);
	close_all();
	exit(*current_exit_code());
}

void	ft_exit_dmm(char **argv)
{
	(void)argv;
}
