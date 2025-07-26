NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRC = ft_printf.c \
	  ft_vprintf.c \
	  ft_convert.c \
	  ft_convert2.c \
	  ft_format.c \
	  ft_countdigits.c \
	  ft_countlen.c \
	  ft_toa.c \
	  ft_utils.c
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ) ft_printf.h
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus