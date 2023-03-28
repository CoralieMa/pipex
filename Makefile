# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 11:14:48 by cmartino          #+#    #+#              #
#    Updated: 2023/03/27 14:58:14 by cmartino         ###   ########.fr        #
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

FILES_BONUS = main_bonus \
				ft_execution_bonus \
				ft_utils_bonus \
				ft_flags_bonus \
				ft_cmds_bonus \
				ft_exit_bonus \
				ft_path_bonus \
				ft_init_bonus \
				ft_free_bonus

SRCS		= ${addprefix SRCS/, $(addsuffix .c, $(FILES))}

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

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

bonus:	${DEP} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS} ${DEP}

clean:
	@make fclean -C ${LIB_PATH}
	${RM} ${OBJS} ${OBJS_BONUS}
	${RM} ${DEP}

fclean:	clean
	${RM} ${LIB_PATH} ${DEP}
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus