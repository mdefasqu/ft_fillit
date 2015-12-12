# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/14 12:47:55 by mdefasqu          #+#    #+#              #
#    Updated: 2015/12/08 12:30:21 by mdefasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

COMPIL = gcc -Wall -Wextra -Werror

SRC = $(shell ls -1 | grep "\.c")

HEADER = $(shell ls -1 | grep "\.h")

OBJ = $(SRC:%.c=%.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
		@cd libft ; $(MAKE) -f Makefile
		@$(COMPIL) -c $(SRC)
		@$(COMPIL) -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[0;32mCompilation de fillit et libft.\033[0;33m"

clean:
		@/bin/rm -f $(OBJ)
		@cd libft ; $(PHONY make clean)
		@echo "\033[0;32mClean de fillit et libft.\033[0;33m"

fclean: clean
		@/bin/rm -f $(NAME)
		@cd libft ; $(PHONY) make fclean
		@echo "\033[0;32mFclean de fillit et libft.\033[0;33m"

re: fclean all
