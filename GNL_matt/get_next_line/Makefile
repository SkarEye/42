NAME = gnl.a
NAME_BONUS = gnl_bonus.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRC =   get_next_line.c \
        get_next_line_utils.c

BONUS_SRC = get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_OBJ)
	$(AR) $(NAME_BONUS) $(BONUS_OBJ)

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