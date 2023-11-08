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
			ft_putstr.c \
			arg_c.c \
			arg_s.c \
			arg_d.c \
			arg_x.c \
			arg_u.c \
			arg_p.c \
			arg_percent.c

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
		make -C $(LIBFT_DIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all clean fclean re