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

SRC = main.c ft_sha.c ft_md5.c ft_global.c ft_sha_384_512.c init_start_words.c \
	  ft_main_hash_function.c ft_parse_and_read.c ft_sha_helpers.c \
	  ft_md5_rounds.c ft_md5_instead_def.c ft_init_structs.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	@gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo ssl_md5 object deleted

fclean: clean

re: fclean all

.PHONY: clean fclean all re
