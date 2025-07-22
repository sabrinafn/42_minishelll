# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:29:33 by feguimar          #+#    #+#              #
#    Updated: 2025/02/01 16:49:00 by feguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

LIBFT_DIR := ./libft
LIBFT := libft/libft.a

CC := cc 
CFLAGS := -g -Wall -Wextra -Werror

LINKER_FLAGS := -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -lreadline

ENV_VARS_FOLDER := env_vars/expand_environment_vars.c  env_vars/ft_getenv.c \
				env_vars/store_environment_vars.c env_vars/env_validation_functions.c \
				env_vars/free_env_list.c env_vars/get_variable_and_value.c 

ENV_VARS_UTILS_FOLDER := env_vars/env_vars_utils/add_env_var.c env_vars/env_vars_utils/find_previous_var_in_list.c \
	env_vars/env_vars_utils/find_var_node.c env_vars/env_vars_utils/remove_env_var.c \
	env_vars/env_vars_utils/remove_first_env_var.c

PROMPT_FOLDER := prompt/get_prompt.c

STATICS_FOLDER := statics/env_vars_list.c statics/args_list.c statics/current_exit_code.c \
	statics/prog_pid.c statics/running_loop.c statics/command_lst.c \
	statics/free_statics.c statics/child_process.c

UTILS_FOLDER := utils/free_split.c \
				utils/ft_redirect_error.c utils/dump_from_file.c utils/compare_str.c \
				utils/wipe_file.c utils/reset_tty.c \
				utils/write_stderr.c utils/write_human_stdout.c utils/print_args_lst.c \
				utils/free_args_list.c utils/ft_free_split.c utils/command_lst_utils.c \
				utils/free_commands.c

PARSING_FOLDER := parsing/create_node.c parsing/split_by_quotes.c parsing/split_by_redirects.c \
	parsing/split_by_spaces.c parsing/unclosed_quotes.c parsing/ft_lexer.c \
	parsing/ft_lst_split.c parsing/ft_strcmp.c

RUN_COMMANDS_FOLDER := run_commands/run_commands.c run_commands/parse_redirect.c \
	run_commands/redirect_output.c run_commands/make_array.c run_commands/open_file.c run_commands/add_word.c \
	run_commands/run_curr_command.c

EXECUTE_COMMAND_FOLDER := run_commands/execute_command/execute_command.c run_commands/execute_command/search_in_path.c \
	run_commands/execute_command/run_from_root.c run_commands/redirect_input.c

BUILT_INS_FOLDER := run_commands/built-ins/fill_cmds.c run_commands/built-ins/ft_cd.c \
	run_commands/built-ins/ft_echo.c run_commands/built-ins/ft_env.c run_commands/built-ins/ft_exit_cmd.c \
	run_commands/built-ins/ft_export.c run_commands/built-ins/ft_pwd.c run_commands/built-ins/ft_unset.c \
	run_commands/built-ins/is_built_in.c run_commands/built-ins/split_env.c run_commands/built-ins/has_equal_sign.c \
	run_commands/built-ins/split_command.c
	
SET_IO_FOLDER := run_commands/set_io/input_from_file.c run_commands/set_io/input_from_pipe.c \
	run_commands/set_io/io_redirects.c run_commands/set_io/output_to_file.c run_commands/set_io/output_to_pipe.c run_commands/set_io/set_process_io.c

SIGNALS_FOLDER := signals/handle_signals.c signals/handle_heredoc_signals.c

SYNTAX_FOLDER := syntax/handle_syntax.c syntax/checking_functions.c syntax/remove_quotes.c \
				 syntax/checking_functions2.c

HEREDOC_FOLDER := run_commands/heredoc/expand_env_vars_heredoc.c run_commands/heredoc/expand_vars_to_string.c \
	run_commands/heredoc/ft_envlen.c run_commands/heredoc/get_var_value_heredoc.c run_commands/heredoc/heredoc_expand.c \
	run_commands/heredoc/heredoc.c run_commands/heredoc/not_end_env_var.c run_commands/heredoc/strlen_expanded.c

LST_ENV_VARS_ORDERED_FOLDER := env_vars/env_vars_utils/lst_env_vars_ordered/add_in_place.c \
	env_vars/env_vars_utils/lst_env_vars_ordered/lst_env_vars_ordered.c env_vars/env_vars_utils/lst_env_vars_ordered/var_dup.c \
	env_vars/env_vars_utils/lst_env_vars_ordered/print_env_vars_list.c env_vars/env_vars_utils/lst_env_vars_ordered/clear_env_vars_lst.c

SRCS := main.c $(ENV_VARS_FOLDER) $(PROMPT_FOLDER) $(STATICS_FOLDER) \
	$(UTILS_FOLDER) $(PARSING_FOLDER) $(RUN_COMMANDS_FOLDER) $(BUILT_INS_FOLDER) \
	$(EXECUTE_COMMAND_FOLDER) $(SET_IO_FOLDER) $(SIGNALS_FOLDER) $(SYNTAX_FOLDER) \
	$(HEREDOC_FOLDER) $(ENV_VARS_UTILS_FOLDER) $(LST_ENV_VARS_ORDERED_FOLDER)

OBJECTS := $(SRCS:.c=.o)

HEADERS := minishell.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all bonus

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LINKER_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean

fclean:
	@make clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

v: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --trace-children-skip='*/bin/*,*/sbin/*' --keep-debuginfo=yes \
	--suppressions=readline.supp --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re v
