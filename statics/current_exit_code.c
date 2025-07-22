/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:13:34 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/30 10:49:33 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*current_exit_code(void)
{
	static int	exit_code;

	return (&exit_code);
}
