/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:12:53 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/28 14:15:43 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

int	check_input_redirect(t_args_lst **arg_lst)
{
	t_args_lst	*args;

	args = *arg_lst;
	while (args->next)
		args = args->next;
	if (args->type == operators)
		return (0);
	return (1);
}

int	single_pipe_at_beginning(t_args_lst **args_lst)
{
	t_args_lst	*args;

	args = *args_lst;
	if (args->type == operators && args->arg[0] == '|')
		return (0);
	return (1);
}
