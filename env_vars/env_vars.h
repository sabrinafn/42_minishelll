/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:00:40 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/04 15:48:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_H
# define ENV_VARS_H

# include "../minishell.h"

// expand_environment_vars.c
void		handle_environment_vars_expansion(char **str);
int			handle_dollar_expansion(char **str, int index, bool *single_quotes);
void		update_quotes(char c, bool *single_quotes, bool *double_quotes);
char		*ft_expand(char **str, int *i);

// env_validation_functions.c
int			is_single_quote(char *str, int i);
int			is_inside_double_quotes(char *str, int pos);
void		remove_dollar_sign(char **str, int i);

// free_env_list.c
void		env_free_lst(t_envp_lst **node);
void		free_env_lst(t_envp_lst **env_lst);

// ft_getenv.c
char		*ft_getenv(char *variable);

// get_variable_and_value.c
char		*parse_var_found(char *str);
char		*get_var_value(char *var);

// store_environment_vars.c
t_envp_lst	*store_envp(char **envp);
void		add_to_lst(t_envp_lst **env_var, char *env);
int			find_pos_strchr(char *str, char c);

#endif
