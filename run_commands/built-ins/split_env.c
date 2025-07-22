/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:30:50 by fernando          #+#    #+#             */
/*   Updated: 2024/12/02 22:33:23 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**split_env(char **argv)
{
	int		i;
	char	**ret;

	i = 1;
	while (has_equal_sign(argv[i]))
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[0] = ft_strdup(argv[0]);
	i = 1;
	while (has_equal_sign(argv[i]))
	{
		ret[i] = ft_strdup(argv[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
