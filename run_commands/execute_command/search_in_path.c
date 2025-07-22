/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:32:47 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 19:04:18 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_path(char *pathname, char **envp)
{
	char	*temp;
	int		i;

	i = 0;
	if (pathname[1] == '.')
	{
		temp = ft_strdup(pathname + 1);
		return (temp);
	}
	while (envp[i] != NULL)
	{
		temp = ft_strjoin(envp[i], pathname);
		if (access(temp, F_OK | X_OK) == 0)
			break ;
		free(temp);
		temp = NULL;
		i++;
	}
	return (temp);
}

void	write_and_exit(char *str, int err_value, char ***argv, char **path)
{
	write_stderr(str, 1);
	free_split(argv);
	*argv = NULL;
	free(*path);
	*path = NULL;
	close_all();
	exit(err_value);
}

void	check_extra_errors_in_exec(char **path_found, char **envp_arr,
		char ***cmd_flags)
{
	struct stat	path_data;

	stat(*path_found, &path_data);
	if ((S_ISDIR(path_data.st_mode) != 0) || (access(*path_found, X_OK) != 0))
	{
		free_env_lst(env_vars_list(0));
		free_split(&envp_arr);
		if (S_ISDIR(path_data.st_mode) != 0)
			write_and_exit(" Is a directory", 126, cmd_flags, path_found);
		if (access(*path_found, X_OK) != 0)
			write_and_exit(" Permission denied", 126, cmd_flags, path_found);
	}
}

void	search_in_path(char *command, char **cmd_flags, char **path,
		char **envp_arr)
{
	char	*path_found;

	path_found = find_path(command, path);
	free(command);
	free_split(&path);
	if ((path_found == NULL) || (access(path_found, F_OK) != 0))
	{
		free_env_lst(env_vars_list(0));
		free_split(&envp_arr);
		if (path_found == NULL)
			write_and_exit(" command not found", 127, &cmd_flags, &path_found);
		if (access(path_found, F_OK) != 0)
			write_and_exit(" No such file or directory", 127, &cmd_flags,
				&path_found);
	}
	check_extra_errors_in_exec(&path_found, envp_arr, &cmd_flags);
	execve(path_found, cmd_flags, envp_arr);
	close_all();
	free_env_lst(env_vars_list(0));
	exit(127);
}
