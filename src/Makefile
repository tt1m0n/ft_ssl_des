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

SRC = ft_add_flags1.c ft_add_flags2.c ft_base64.h ft_base64_decrypt.c \
    ft_base64_decrypt_operations.c ft_base64_encrypt.c \
    ft_base64_encrypt_operations.c ft_base64_operations.c \
    ft_base64_output.c ft_cbc_pre_post_block.c ft_crypt_operations.c \
    ft_des.c ft_des3.c ft_des3_operations.c ft_des_align_input.c \
    ft_des_block_operation.c ft_des_block_permutation.c \
    ft_des_common_block_operation.c ft_des_key_operations.c \
    ft_des_key_operations1.c ft_des_key_operations2.c ft_des_key_operations3.c \
    ft_des_operations.c ft_des_output.c ft_des_pad.c ft_des_round.c \
    ft_des_salt_operation.c ft_des_sbox.c ft_des_validate_hex.c \
    ft_flags_operations.c ft_print_functions.c ft_print_show_des.c ft_read_text.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo crypt_src object deleted

fclean: clean

re: fclean all

.PHONY: clean fclean all re
