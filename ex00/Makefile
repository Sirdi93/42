# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 14:07:26 by ple-lez           #+#    #+#              #
#    Updated: 2022/07/24 17:37:17 by ple-lez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rush-02

INC_DIR=./includes/
SRC_DIR=./srcs/
SRC=main.c ft_parsing.c ft_list.c ft_utils.c ft_algo.c ft_cleanup.c \
	ft_strings.c ft_error.c ft_split.c ft_strjoin.c ft_init.c
SRCS=$(addprefix ${SRC_DIR}, ${SRC})
OBJS=${SRCS:.c=.o}

CC=gcc
FLAGS=-Wall -Wextra -Werror
RM=rm -f

.c.o:
	${CC} ${FLAGS} -I${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re reclean
