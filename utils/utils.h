/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:01:47 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 18:08:58 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

void		free_split(char ***spl);
void		ft_quote_error(void);
void		ft_redirect_error(void);
void		dump_from_file(int in_file, int out_file);
int			compare_str(char *str1, char *str2);
void		wipe_file(int fd);
void		reset_terminal_settings(void);
void		write_stderr(char *str, int eol);
void		write_human_stdout(char *str, int eol);
void		print_args_lst(t_args_lst *ptr);

// functions to free args list
void		free_lst(t_args_lst *node);
void		free_args_list(t_args_lst **args_lst);

// function to free split
void		ft_free_split(char **arr);

void		push_command(t_command *new_command);
t_command	*pop_command(void);
t_command	*new_command(int run);
void		free_t_command(t_command **cmd);
void		free_cmd_lst(t_command **head);

// function to free builtins
void		free_commands(t_built_in *cmds);
#endif
