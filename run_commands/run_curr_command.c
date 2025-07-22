/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_curr_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:36:10 by fernando          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:24 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_exit_code_builtins(char **command_line)
{
	if ((command_line[1] != NULL) && (command_line[2] != NULL))
	{
		write_stderr(" too many arguments", 1);
		*current_exit_code() = 1;
	}
	else if ((command_line[1] != NULL) && (command_line[2] == NULL))
		*current_exit_code() = convert_exit_value(command_line[1]);
	else
		*current_exit_code() = 0;
}

void	execute_built_ins(char **command_line, char ***e, t_pipe **pipeline)
{
	if ((((*curr_cmd())->comm) != NULL)
		&& (ft_strcmp(((*curr_cmd())->comm)->arg, "export") == 0))
		ft_export_run(command_line);
	if ((((*curr_cmd())->comm) != NULL)
		&& (ft_strcmp(((*curr_cmd())->comm)->arg, "unset") == 0))
		ft_unset_run(command_line);
	if ((((*curr_cmd())->comm) != NULL)
		&& (ft_strcmp(((*curr_cmd())->comm)->arg, "cd") == 0))
		ft_cd_run(command_line);
	if ((((*curr_cmd())->comm) != NULL)
		&& (ft_strcmp(((*curr_cmd())->comm)->arg, "exit") == 0))
	{
		if (count_blocks(*args_list()) != 1)
		{
			update_exit_code_builtins(command_line);
			return ;
		}
		free(*pipeline);
		free_split(e);
		free_t_command(curr_cmd());
		ft_exit_cmd(command_line);
	}
}

void	run_curr_command(t_pipe **pipeline, int total_blocks)
{
	char	**command_line;
	char	**env_path;
	pid_t	pid;

	if (ft_getenv("PATH") == NULL)
		env_path = ft_split("", ':');
	else
		env_path = ft_split(ft_getenv("PATH"), ':');
	command_line = make_array((*curr_cmd())->comm);
	execute_built_ins(command_line, &env_path, pipeline);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, handle_sigint_signal);
		rl_clear_history();
		set_process_io(pipeline, total_blocks);
		if (!is_built_in(command_line[0], command_line, env_path))
			execute_command(command_line, env_path);
		exit(*current_exit_code());
	}
	if ((*curr_cmd())->not_last == 0)
		*last_pid() = pid;
	free_t_command(curr_cmd());
	free_split(&env_path);
	free_split(&command_line);
}

void	print_split(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s", tokens[i]);
		if (tokens[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	close_all(void)
{
	int	i;
	int	r;

	i = 0;
	while (i < 1024)
	{
		r = read(i, NULL, 0);
		if (r == 0)
			close(i);
		r = write(i, NULL, 0);
		if (r == 0)
			close(i);
		i++;
	}
}
