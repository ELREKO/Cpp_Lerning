# Compiler and flags
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDES_DIR = includes
LIB_DIR = ../lib/console_setting/src

# List of source files (excluding main.cpp)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(LIB_DIR)/*.cpp)

# Derive object file names from source file names
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC_FILES)))

# Executable name
EXECUTABLE = Serializer

# Targets
all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJ_DIR)/main.o
	$(CXX) $(CPPFLAGS) $^ -o $@

# Rule to compile .cpp files in src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -I$(LIB_DIR) -c $< -o $@

# Rule to compile .cpp files in lib
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -I$(LIB_DIR) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -I$(LIB_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
