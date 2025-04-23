NAME = gnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRC =   get_next_line_utils.c \
        get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus