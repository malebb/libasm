# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2021/02/05 14:13:58 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s \
	   ft_atoi_base.s ft_list_size.s ft_list_push_front.s

OBJS = ${SRCS:.s=.o}

AS = nasm
ASFLAGS = -f elf64

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libasm.a
RM	= rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

bonus:		${NAME}

re:			fclean all
