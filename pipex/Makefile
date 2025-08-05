#     _/_/_/       _/_/_/    _/_/_/       _/_/_/_/    _/      _/  
#    _/    _/       _/      _/    _/     _/            _/  _/     
#   _/_/_/         _/      _/_/_/       _/_/_/          _/        
#  _/             _/      _/           _/            _/  _/       
# _/           _/_/_/    _/           _/_/_/_/    _/      _/      
# === Project name ===
NAME := pipex

# === Compiler and Flags ===                                                                                        
CC := cc
CFLAGS := -Wall -Wextra -Werror -Iincludes
RM := rm -f
MKDIR := mkdir -p

# === Libraries ===

# === Object folder ===
OBJ_DIR := .objects

# === Source files ===
SRC := 
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
	$(MAKE) -C clean
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
