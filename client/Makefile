NAME = client
CXX = c++
RM = rm -f

CXXERRFLAGS = -Wall -Wextra -Werror
CXXSTD = -std=c++17

SRC_DIR = ./
BUILD_DIR = build
LIB_DIR = ../config
INCLUDE_DIRS = $(LIB_DIR)

INCLUDES = $(addprefix -I,$(INCLUDE_DIRS))

CXXFLAGS = $(CXXERRFLAGS) $(CXXSTD) $(INCLUDES)

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

LIBS = -L$(LIB_DIR) -lconfig -lzmq

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
RESET  = \033[0;37m

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@$(CXX) $(DEBUG) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)[client] - The executable $@ is ready$(RESET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)[client] - Compiled $< → $@$(RESET)"

$(LIBS):
	@$(MAKE) --no-print-directory -C $(LIB_DIR)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)[client] - The object files are removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[client] - The executable is removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

