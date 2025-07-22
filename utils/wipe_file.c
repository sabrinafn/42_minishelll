/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:28:20 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 14:23:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wipe_file(int fd)
{
	char	*buf;
	int		i;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		buf = malloc(100);
		i = read(fd, buf, 100);
		while (i > 0)
		{
			i = read(fd, buf, 100);
		}
		free(buf);
	}
	else
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGKILL);
	}
}
