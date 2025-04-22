NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRC = \
        src_libc/ft_atoi.c \
        src_libc/ft_bzero.c \
        src_libc/ft_calloc.c \
        src_libc/ft_isalnum.c \
        src_libc/ft_isalpha.c \
        src_libc/ft_isascii.c \
        src_libc/ft_isdigit.c \
        src_libc/ft_isprint.c \
        src_libc/ft_memchr.c \
        src_libc/ft_memcmp.c \
        src_libc/ft_memcpy.c \
        src_libc/ft_memmove.c \
        src_libc/ft_memset.c \
        src_libc/ft_strchr.c \
        src_libc/ft_strdup.c \
        src_libc/ft_strlcat.c \
        src_libc/ft_strlcpy.c \
        src_libc/ft_strlen.c \
        src_libc/ft_strncmp.c \
        src_libc/ft_strnstr.c \
        src_libc/ft_strrchr.c \
        src_libc/ft_tolower.c \
        src_libc/ft_toupper.c \
		src_supp/ft_substr.c \
		src_supp/ft_strjoin.c \
		src_supp/ft_strtrim.c \
		src_supp/ft_split.c \
        src_supp/ft_itoa.c \
        src_supp/ft_strmapi.c \
        src_supp/ft_striteri.c \
        src_supp/ft_putchar_fd.c \
        src_supp/ft_putstr_fd.c \
        src_supp/ft_putendl_fd.c \
        src_supp/ft_putnbr_fd.c \

BONUS_SRC = \
        src_lst/ft_lstnew_bonus.c \
        src_lst/ft_lstadd_front_bonus.c \
        src_lst/ft_lstsize_bonus.c \
        src_lst/ft_lstlast_bonus.c \
        src_lst/ft_lstadd_back_bonus.c \
        src_lst/ft_lstdelone_bonus.c \
        src_lst/ft_lstclear_bonus.c \
        src_lst/ft_lstiter_bonus.c \
        src_lst/ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus