# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:57:02 by cmartino          #+#    #+#              #
#    Updated: 2023/04/07 14:59:31 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

FILES		= main \
				utils \
				cmds \
				exit \
				free \
				execution \
				get_paths \
				initialise

SRCS		= ${addprefix SRCS/, $(addsuffix .c, $(FILES))}

OBJS		= ${SRCS:.c=.o}

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror# -fsanitize=address -g

RM			= rm -f

LIB_PATH	= libft/

DEP 		= libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :	${NAME}

${NAME}:	${DEP} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${DEP}

${DEP}:		
		@make -C ${LIB_PATH}
		@mv libft/${DEP} libft.a

clean:
	@make fclean -C ${LIB_PATH}
	${RM} ${OBJS} ${OBJS_BONUS}
	${RM} ${DEP}

fclean:	clean
	${RM} ${LIB_PATH}${DEP}
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
