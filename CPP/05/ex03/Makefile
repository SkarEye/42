#  _______  _______  _______ 
# |       ||       ||       |
# |       ||    _  ||    _  |
# |       ||   |_| ||   |_| |  ___   _ _
# |      _||    ___||    ___| |   | |  _|
# |     |_ |   |    |   |     | | | |_  |
# |_______||___|    |___|     |___| |___|
# === Project name ===
DIR			= ex03
NAME		= interns

# === Compiler and Flags ===
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD -MP
EXPLICIT 	:= 0

# === Directories ===
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= .obj

# === Source files ===
SRC_FILES	= Bureaucrat.cpp \
			  Intern.cpp \
			  AForm.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  main.cpp

# === Object files ===
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

# === Includes ===
INCLUDES	= -I$(INC_DIR)

# === Paths ===
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
DEP			= $(OBJ:.o=.d)

# === Escape codes ===
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
RED			= \033[31m
PURPLE		= \033[35m
GRAY		= \033[90m
UP			= \033[A
CLEAR		= \033[2K

# === Build rules ===
BUILD		?= Default
DEBUG_MSG	:=

ifeq ($(BUILD), debug)
CFLAGS		+= -g -DDEBUG=1
EXPLICIT	:= 1
DEBUG_MSG	:= @echo "$(PURPLE)DEBUG mode is activated.$(RESET)"
else ifneq ($(BUILD), Default)
$(error Unknown BUILD option: '$(BUILD)'. Valid options are: debug, Default)
endif

# === Default target ===
all: $(NAME)

# === Compilation rules ===
# - Executable -
$(NAME): $(OBJ)
	@echo "$(CLEAR)$(BLUE)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"
	$(DEBUG_MSG)

# - Objects -
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@if [ $(EXPLICIT) -eq 1 ]; then \
		echo "$(YELLOW)Compiling $<...$(RESET)";\
		echo "$(GRAY)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@$(RESET)";\
	else \
		echo "$(CLEAR)$(YELLOW)Compiling $<...$(RESET)$(UP)";\
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# - Dependencies -
-include $(DEP)

# === Cleaning rules ===
# - clean -
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)Removing object files from $(DIR)...$(RESET)"; \
	else \
		echo "$(YELLOW)No object files to remove from $(DIR).$(RESET)"; \
	fi

# - fclean -
fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(RED)Removing executable $(NAME) from $(DIR)...$(RESET)"; \
	else \
		echo "$(YELLOW)No executable $(NAME) to remove from $(DIR).$(RESET)"; \
	fi

# - re -
re: fclean all

# === Help ===
help:
	@echo "Makefile for $(NAME) in $(DIR)\n\n\
	Available targets:\n\
	  all     - Compile the project (default)\n\
	  clean   - Remove object files\n\
	  fclean  - Remove object files and executable\n\
	  re      - Recompile the project\n\
	  help    - Display this help message\n\n\
	Build options:\n\
	  BUILD=debug  - Compile with debug information\n\n\
	Set EXPLICIT=1 to show detailed compilation output."


.PHONY: all clean fclean re help