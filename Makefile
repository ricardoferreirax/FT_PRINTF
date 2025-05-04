# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 22:04:24 by rmedeiro          #+#    #+#              #
#    Updated: 2025/05/04 18:25:53 by rmedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
COMPRESS = ar rcs

SRCS = ft_handle_char.c ft_handle_integer.c ft_handle_hexadecimal.c \
       ft_handle_pointer.c ft_handle_string.c ft_handle_unsigned.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo "Library $(NAME) created!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "Cleaned object files."

fclean: clean
	@$(RM) $(NAME)
	@echo "All cleaned up: $(NAME)!"

re: fclean all

.PHONY: all clean fclean re