/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2025/02/02 18:05:00 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_IO_H
# define SET_IO_H

# include "../../minishell.h"

void	input_from_file(int *file);
void	input_from_pipe(t_pipe *pipe);
int		is_output_to_file(char *s);
int		is_input_from_file(char *s);
int		is_input_from_heredoc(char *s);
void	output_to_file(int *file);
void	output_to_pipe(t_pipe *pipe);
void	set_process_io(t_pipe **pipeline, int t);
void	close_pipes(t_command *command, t_pipe **pipeline, int t);
void	close_t_pipe(t_pipe pipe);

#endif
