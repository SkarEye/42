# ________________________________________________
# _/\/\/\/\/\/\____________/\/\______/\/\/\/\/\/\_
# _/\/\____________________/\/\______/\/\_________
# _/\/\/\/\/\__________/\/\/\/\______/\/\/\/\/\___
# _/\/\______________/\/\__/\/\______/\/\_________
# _/\/\________________/\/\/\/\______/\/\_________
# ________________________________________________


# === Project name ===
NAME := fdf

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
OBJ_DIR := .objects

# === Source files ===
SRC_DIR := src/
EXIT	:= exit/
IMG		:= image/
PROJ	:= projections/
UTILS	:= utils/
SRC := \
	main.c \
	$(SRC_DIR)$(UTILS)ft_atoi.c \
	$(SRC_DIR)$(UTILS)ft_bzero.c \
	$(SRC_DIR)$(UTILS)ft_htoui.c \
	$(SRC_DIR)$(UTILS)ft_itoa.c \
	$(SRC_DIR)$(UTILS)ft_join.c \
	$(SRC_DIR)$(UTILS)ft_split.c \
	$(SRC_DIR)$(UTILS)ft_strchr.c \
	$(SRC_DIR)$(UTILS)ft_strdup.c \
	$(SRC_DIR)$(UTILS)ft_strlcpy.c \
	$(SRC_DIR)$(UTILS)ft_strlen.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)map_utils.c \
	$(SRC_DIR)math_helper.c \
	$(SRC_DIR)$(IMG)pixel_utils.c \
	$(SRC_DIR)$(IMG)img_utils.c \
	$(SRC_DIR)$(IMG)img_utils2.c \
	$(SRC_DIR)$(PROJ)draw.c \
	$(SRC_DIR)$(PROJ)project.c \
	$(SRC_DIR)$(EXIT)error_utils.c \
	$(SRC_DIR)$(EXIT)exit_utils.c \
	$(SRC_DIR)$(EXIT)exit_wrappers.c



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
