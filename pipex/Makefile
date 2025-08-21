#     _/_/_/       _/_/_/    _/_/_/       _/_/_/_/    _/      _/  
#    _/    _/       _/      _/    _/     _/            _/  _/     
#   _/_/_/         _/      _/_/_/       _/_/_/          _/        
#  _/             _/      _/           _/            _/  _/       
# _/           _/_/_/    _/           _/_/_/_/    _/      _/      
# === Project name ===
NAME := pipex

# === Compiler and Flags ===                                                                                        
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iincludes -MMD -Wpadded
RM := rm -f
MKDIR := mkdir -p

# === Libraries ===

# === Object folder ===
OBJ_DIR := .objects

# === Source files ===
SRC := \
pipex.c \
src/exit/error_utils.c \
src/exit/exit_utils.c \
src/exit/exit_wrappers.c \
src/exit/exit_wrappers2.c \
src/utils/ft_bzero.c \
src/utils/ft_free_strtab.c \
src/utils/ft_is_whitespace.c \
src/utils/ft_itoa.c \
src/utils/ft_join.c \
src/utils/ft_memcpy.c \
src/utils/ft_strchr.c \
src/utils/ft_split.c \
src/utils/ft_strcmp.c \
src/utils/ft_strdup.c \
src/utils/ft_strlcpy.c \
src/utils/ft_strlen.c \
src/utils/ft_strncmp.c \
src/utils/ft_strtabndup.c \
src/get_next_line.c \
src/exec_utils.c \
src/path_utils.c

# === Object and Dependency files ===
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

# === Default target ===
all: $(NAME)

# === Linking ===
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# === Compilation rule ===
$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === Include dependencies ===
-include $(DEP)

# === Cleaning ===
clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
