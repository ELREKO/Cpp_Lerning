
OBJ_DIR = build
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I../ex00/src -I../ex01/src -I../ex02/src
CXX = c++
RM = rm -f

SRC_DIR = src
EX00_SRC_DIR = ../ex00/src
EX01_SRC_DIR = ../ex01/src
EX02_SRC_DIR = ../ex02/src

# List all source files
SOURCES = $(SRC_DIR)/DiamondTrap.cpp $(EX00_SRC_DIR)/ClapTrap.cpp $(EX01_SRC_DIR)/ScavTrap.cpp $(EX02_SRC_DIR)/FragTrap.cpp
# Derive object file names from source file names
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

# Executable name
EXECUTABLE = DiamondTrap

# Include main.cpp directly
MAIN_SRC = main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EX00_SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EX01_SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EX02_SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC) | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
