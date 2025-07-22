/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2025/02/04 18:30:32 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMAND_H
# define EXECUTE_COMMAND_H

# include "../../minishell.h"

void	execute_command(char **command_line, char **env_path);
void	run_from_root(char *command, char **cmd_flags, char **envp_arr);
void	search_in_path(char *pathname, char **argv, char **envp,
			char **real_envp_arr);
void	write_and_exit(char *str, int err_value, char ***argv, char **path);
int		get_lstsize(t_envp_lst *lst);
char	**envp_lst_to_array(t_envp_lst **envp_lst);
char	*find_path(char *pathname, char **envp);
void	remove_one_quote(char **str, int i);

#endif
