NAME       = libconfig.a
CXX        = c++
AR         = ar rcs
RM         = rm -f

RED        = \033[1;31m
GREEN      = \033[1;32m
YELLOW     = \033[1;33m
RESET      = \033[0;37m
SKY        = \033[1;36m

SRC_DIRS   = ./

INCLUDES   = $(addprefix -I, $(SRC_DIRS) .)

BUILD_DIR  = build

SRCS       = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))
OBJS       = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

CXXERRFLAGS = -Wall -Wextra -Werror
CXXFLAGS    = $(CXXERRFLAGS) -std=c++17 $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)[config] - The static library $@ is ready$(RESET)"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)[config] - Compiled $< → $@$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)[config] - The object files are removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[config] - The static library is removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

