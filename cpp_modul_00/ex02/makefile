OBJ_DIR = build
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
CXX = g++
RM = rm -f

SRC_DIR = src
INCLUDES_DIR = includes

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Derive object file names from source file names
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable name
EXECUTABLE = dream

all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
