# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thclarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:23:31 by thclarac          #+#    #+#              #
#    Updated: 2023/04/06 14:23:38 by thclarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRCS =  ft_printf.c fonct_aux.c

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

OBJS = ${SRCS:.c=.o}
all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME)$(OBJS)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
