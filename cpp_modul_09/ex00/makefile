# Compiler and flags
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR = src
INCLUDES_DIR = include
OBJ_DIR = build

# Source files
SRC_FILES = $(SRC_DIR)/BitcoinExchange.cpp
MAIN_FILE = main.cpp

# Derive object file names from source file names
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC_FILES))) $(OBJ_DIR)/main.o

# Executable name
EXECUTABLE = btc

# Targets
all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $@

# Rule to compile src/*.cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

# Rule to compile main.cpp (directly in project root)
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build artifacts
clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
