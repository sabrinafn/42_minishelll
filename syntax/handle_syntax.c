/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:10 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 16:13:47 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

int	handle_syntax(t_args_lst **arg_lst)
{
	if ((!check_unique_operator(arg_lst))
		|| (!check_redirect_and_pipe(arg_lst)))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!check_multiple_operators_in_node(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!single_pipe_at_beginning(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	if (!check_input_redirect(arg_lst))
	{
		*current_exit_code() = 2;
		return (0);
	}
	return (1);
}
