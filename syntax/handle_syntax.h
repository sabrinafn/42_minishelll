/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:55 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 13:22:37 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SYNTAX_H
# define HANDLE_SYNTAX_H

# include "../minishell.h"

char	*remove_quotes(char **str);
void	check_quotes_and_remove(char **str);
int		handle_syntax(t_args_lst **arg_lst);
int		get_args_size(t_args_lst *lst);
int		check_unique_operator(t_args_lst **arg_lst);
int		check_multiples(char *str);
int		check_multiple_operators_in_node(t_args_lst **arg_lst);
int		single_pipe_at_beginning(t_args_lst **args_lst);
int		check_input_redirect(t_args_lst **arg_lst);
int		check_redirect_and_pipe(t_args_lst **arg_lst);
#endif
