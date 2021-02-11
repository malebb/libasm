# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2021/02/11 18:39:46 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/mandatory/ft_strcpy.s srcs/mandatory/ft_strlen.s \
		srcs/mandatory/ft_strcmp.s srcs/mandatory/ft_write.s \
		srcs/mandatory/ft_read.s srcs/mandatory/ft_strdup.s 

BONUS =	srcs/bonus/ft_atoi_base_bonus.s srcs/bonus/ft_list_size_bonus.s \
		srcs/bonus/ft_list_push_front_bonus.s srcs/bonus/ft_list_sort_bonus.s \
		srcs/bonus/ft_list_remove_if_bonus.s

OBJS = ${SRCS:.s=.o}
OBJS_BONUS = ${BONUS:.s=.o}

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
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

bonus:		${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

re:			fclean all
