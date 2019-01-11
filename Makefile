# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:39 by omakovsk          #+#    #+#              #
#    Updated: 2018/08/25 19:53:34 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
OBJ =  objects/*.o
LIBNAME = objects/libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): objectdir
	@make -C libft
	@make -C hash_src
	@ar rc $(LIBNAME) $(OBJ)
	@gcc $(FLAGS) $(LIBNAME) -o $(NAME) 
	@echo "\033[35m --------- ready ------------\033[0m"

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C md5_src
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m -------------- deleted--------------\033[0m"

re: fclean all

.PHONY: clean all fclean re
