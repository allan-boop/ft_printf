#########################################
## ARGUMENTS

NAME		= libftprintf.a
CFLAGS		= -Wextra -Wall -Werror -c
CC			= gcc

########################################
## SOURCES

SRC_FILES =	ft_printf.c

OBJ_FILES =	$(SRC_FILES:.c=.o)

BONUS			=	

BONUS_OBJS		= $(BONUS:.c=.o)

########################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
			${AR} rcs ${NAME} ${OBJ_FILES}
clean: 
		rm -f ${OBJ_FILES} ${BONUS_OBJS}
fclean: clean
		rm -f ${NAME}
re: fclean all

bonus: $(OBJ_FILES) $(BONUS_OBJS)
		${AR} rcs $(NAME) $(OBJ_FILES) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus