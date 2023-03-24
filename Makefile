# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 11:14:48 by cmartino          #+#    #+#              #
#    Updated: 2023/03/24 13:52:20 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

FILES		= main \
				ft_execution \
				ft_utils \
				ft_flags \
				ft_cmds \
				ft_exit \
				ft_path \
				ft_init \
				ft_free

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
		mv libft/${DEP} libft.a

clean:
	@make fclean -C ${LIB_PATH}
	${RM} ${OBJS}
	${RM} ${DEP}

fclean:	clean
	${RM} ${LIB_PATH}${DEP}
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re