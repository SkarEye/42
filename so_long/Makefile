# === Project name ===
NAME := so_long

# === Compiler and Flags ===
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iincludes -Imlx -MMD -MP
RM := rm -f
MKDIR := mkdir -p

# === Libraries ===
MLX_DIR := mlx
MLX_LIB := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# === Object folder ===
OBJ_DIR := objects

# === Source files ===
SRC := \
	main.c \
	src/gnl/get_next_line.c \
	src/gnl/get_next_line_utils.c \
	src/utils/exit_utils.c \
	src/utils/list_utils.c \
	src/utils/map_utils.c

# === Object and Dependency files ===
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

# === Default target ===
all: $(NAME)

# === Linking ===
$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)

# === MLX library ===
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# === Compilation rule ===
$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === Include dependencies ===
-include $(DEP)

# === Cleaning ===
clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
