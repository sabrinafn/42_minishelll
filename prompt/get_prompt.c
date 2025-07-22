/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:43:25 by fernando          #+#    #+#             */
/*   Updated: 2025/01/21 16:21:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*change_color_prompt(char *prompt)
{
	char	*temp;
	char	*new_prompt;

	temp = ft_strjoin(GREEN, prompt);
	new_prompt = ft_strjoin(temp, COLOR_RESET);
	free(temp);
	return (new_prompt);
}

char	*get_prompt(void)
{
	char	*user;
	char	*hostname;
	char	*joined;
	char	*prompt;

	if (ft_getenv("USER"))
		user = ft_strdup(ft_getenv("USER"));
	else
		user = ft_strdup("USER");
	hostname = ft_strdup("@minishell: ");
	joined = ft_strjoin(user, hostname);
	prompt = change_color_prompt(joined);
	free(user);
	free(hostname);
	free(joined);
	return (prompt);
}
