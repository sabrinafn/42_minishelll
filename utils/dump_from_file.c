/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:04:18 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/15 20:30:16 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dump_from_file(int in_file, int out_file)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * 1024);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(in_file, buffer, sizeof(buffer));
		write(out_file, buffer, bytes_read);
	}
}
