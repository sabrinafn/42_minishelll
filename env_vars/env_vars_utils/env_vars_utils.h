/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 00:49:09 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_UTILS_H
# define ENV_VARS_UTILS_H

# include "../../minishell.h"

void		remove_first_env_var(void);
void		remove_env_var(char *name);
t_envp_lst	*find_var_node(char *name);
t_envp_lst	*find_previous_var_in_list(char *name);
int			is_valid_var(char **elements);
void		add_env_var(char *var);
int			is_valid_var(char **elements);
void		add_variable(char **elements, char *var);
void		list_env_vars_ordered(void);
t_envp_lst	*var_dup(t_envp_lst *var);
int			compare_str(char *str1, char *str2);

#endif
