# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:57:02 by cmartino          #+#    #+#              #
#    Updated: 2023/04/13 10:49:21 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

FILES		= main \
				free \
				cmds \
				exit \
				utils \
				execution \
				get_paths \
				initialise

FILES_BONUS	= main_bonus \
				free_bonus \
				cmds_bonus \
				exit_bonus \
				utils_bonus \
				here_doc_bonus \
				execution_bonus \
				get_paths_bonus \
				initialise_bonus \
				get_next_line \
				get_next_line_utils

SRCS		= ${addprefix SRCS/, $(addsuffix .c, $(FILES))}

SRCS_BONUS	= ${addprefix SRCS_bonus/, $(addsuffix .c, $(FILES_BONUS))}

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror

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

bonus:	${DEP} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME} ${DEP}

re:	fclean all

.PHONY:	all clean fclean re bonus
