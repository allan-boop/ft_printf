#########################################
## ARGUMENTS

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

########################################
## SOURCES

SRC_FILES =	ft_printf.c \

OBJ_FILES =	$(SRC_FILES:.c=.o)

########################################
## RULES

all: ${NAME}

${NAME}: makelibft ${OBJ_FILES}
			${AR} rcs ${NAME} ${OBJ_FILES}
makelibft:
		make -C ${LIBFT_DIR}
		cp ${LIBFT_DIR}/${LIBFT_NAME} .
		mv ${LIBFT_NAME} ${NAME}
clean: 
		rm -f ${OBJ_FILES}
		cd $(LIBFT_DIR) && make clean
		cd -
fclean: clean
		rm -f ${NAME}
		cd $(LIBFT_DIR) && make clean
		cd -
re: fclean all

.PHONY: all clean fclean re