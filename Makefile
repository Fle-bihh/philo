# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 17:24:38 by fle-biha          #+#    #+#              #
#    Updated: 2021/07/05 00:47:59 by fle-biha         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/

OBJS			= $(SRCS:.c=.o)

CC				= @gcc

RM				= @/bin/rm -f

CFLAGS			= -Wall -Wextra -Werror

LIB				= libft/libft.a

NAME			= philo

HEADER			= incs/philo.h

.c.o:			$(HEADER) $(LIB)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			compil $(NAME)

compil:
				@make -C libft

$(OBJS):		$(HEADER)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) $(LIB) -o $(NAME)
				@echo "PHILO COMPILED"

clean:
				$(RM) $(OBJS)
				@make clean -C libft
				@echo "PHILO CLEAN"

fclean:			clean
				$(RM) $(NAME)
				@make fclean -C libft
				@echo "PHILO FCLEAN"

re:				fclean all

.PHONY:			all clean fclean re
