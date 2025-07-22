/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:38:06 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 14:24:59 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_stderr(char *str, int eol)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	if (eol)
		write(STDERR_FILENO, "\n", 1);
}
