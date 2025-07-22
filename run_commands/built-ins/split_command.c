/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:45:59 by fernando          #+#    #+#             */
/*   Updated: 2024/12/03 01:47:22 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*split_command(char **argv)
{
	int		i;
	int		start;
	char	*ret;
	int		total;

	start = 1;
	while (has_equal_sign(argv[start]))
		start++;
	i = start;
	total = 0;
	while (argv[i] != NULL)
	{
		total = total + ft_strlen(argv[i]) + 3;
		i++;
	}
	ret = malloc(sizeof(char *) * (total + 1));
	ft_bzero(ret, total + 1);
	i = start;
	while (argv[i] != NULL)
	{
		ft_strlcat(ret, argv[i], total + 1);
		ft_strlcat(ret, " ", total + 1);
		i++;
	}
	return (ret);
}
