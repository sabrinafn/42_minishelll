/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:23:01 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 15:10:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**make_array(t_args_lst *lst)
{
	int			i;
	t_args_lst	*ptr;
	char		**ret;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	ret = malloc(sizeof(char *) * (i + 1));
	i = 0;
	ptr = lst;
	while (ptr)
	{
		ret[i] = ft_strdup(ptr->arg);
		i++;
		ptr = ptr->next;
	}
	ret[i] = NULL;
	return (ret);
}
