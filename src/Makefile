# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:55 by omakovsk          #+#    #+#              #
#    Updated: 2018/09/02 13:52:55 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -c

SRC = ft_add_flags1.c ft_add_flags2.c ft_base64_decrypt.c \
    ft_base64_decrypt_operations.c ft_base64_encrypt.c \
    ft_base64_encrypt_operations.c ft_base64_operations.c \
    ft_base64_output.c ft_cbc_pre_post_block.c ft_crypt_operations.c \
    ft_des.c ft_des3.c ft_des3_operations.c ft_des_align_input.c \
    ft_des_block_operation.c ft_des_block_permutation.c \
    ft_des_common_block_operation.c ft_des_key_operations.c \
    ft_des_key_operations1.c ft_des_key_operations2.c ft_des_key_operations3.c \
    ft_des_operations.c ft_des_output.c ft_des_pad.c ft_des_round.c \
    ft_des_salt_operation.c ft_des_sbox.c ft_des_validate_hex.c \
    ft_flags_operations.c ft_print_functions.c ft_print_show_des.c ft_read_text.c \
    ft_global.c print_error.c main.c ft_sha.c ft_md5.c ft_global.c \
    ft_sha_384_512.c init_start_words.c ft_main_hash_function.c ft_parse_and_read.c \
    ft_sha_helpers.c ft_md5_rounds.c ft_md5_instead_def.c ft_init_structs.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo objects deleted

fclean: clean

re: fclean all

.PHONY: clean fclean all re
